/**************************************************************************
*
* Copyright (C) 2011 Steve Karg <skarg@users.sourceforge.net>
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
*********************************************************************/
#include <stdint.h>
#include <stdbool.h>
/* hardware layer includes */
#include "hardware.h"
#include "timer.h"
#include "rs485.h"
/* BACnet Stack includes */
#include "datalink.h"
#include "npdu.h"
#include "handlers.h"
#include "client.h"
#include "txbuf.h"
#include "dcc.h"
#include "iam.h"
/* BACnet objects */
#include "device.h"
#include "bo.h"
#include "bi.h"
/* me */
#include "bacnet.h"

/* timer for device communications control */
static struct itimer DCC_Timer;
#define DCC_CYCLE_SECONDS 1
extern char flag_send_compelete;
void bacnet_init(
    void)
{
    dlmstp_set_mac_address(26);
    dlmstp_set_max_master(127);
    /* initialize datalink layer */
    dlmstp_init(NULL);
    /* initialize objects */
    Device_Init(NULL);

    /* set up our confirmed service unrecognized service handler - required! */
    apdu_set_unrecognized_service_handler_handler
        (handler_unrecognized_service);
    /* we need to handle who-is to support dynamic device binding */
    apdu_set_unconfirmed_handler(SERVICE_UNCONFIRMED_WHO_IS, handler_who_is);
    apdu_set_unconfirmed_handler(SERVICE_UNCONFIRMED_WHO_HAS, handler_who_has);
    /* Set the handlers for any confirmed services that we support. */
    /* We must implement read property - it's required! */
    apdu_set_confirmed_handler(SERVICE_CONFIRMED_READ_PROPERTY,
        handler_read_property);
    apdu_set_confirmed_handler(SERVICE_CONFIRMED_READ_PROP_MULTIPLE,
        handler_read_property_multiple);
    apdu_set_confirmed_handler(SERVICE_CONFIRMED_REINITIALIZE_DEVICE,
        handler_reinitialize_device);
    apdu_set_confirmed_handler(SERVICE_CONFIRMED_WRITE_PROPERTY,
        handler_write_property);
    /* handle communication so we can shutup when asked */
    apdu_set_confirmed_handler(SERVICE_CONFIRMED_DEVICE_COMMUNICATION_CONTROL,
        handler_device_communication_control);
	apdu_set_confirmed_ack_handler(SERVICE_CONFIRMED_READ_PROPERTY,
        handler_read_property_ack);
    /* start the cyclic 1 second timer for DCC */
    timer_interval_start_seconds(&DCC_Timer, DCC_CYCLE_SECONDS);
    /* Hello World! */
    //Send_I_Am(&Handler_Transmit_Buffer[0]);
}

static uint8_t PDUBuffer[MAX_MPDU];
void bacnet_task(
    void)
{
    uint16_t pdu_len;
    BACNET_ADDRESS src; /* source address */
    uint8_t i;
    BACNET_BINARY_PV binary_value = BINARY_INACTIVE;
    BACNET_POLARITY polarity;
    bool out_of_service;
	short retVal = -1;
	BACNET_ADDRESS dest;
	BACNET_APPLICATION_DATA_VALUE object_value;
	dest.mac[0] = 14;
	dest.mac_len = 1;
	dest.net = 0;
	dest.adr[0] = 14;
	dest.len = 1;
	
	object_value.type.Enumerated = 1;
	object_value.tag = BACNET_APPLICATION_TAG_REAL;
	object_value.context_specific = 0;
	object_value.next = NULL;
    /* Binary Output */
    for (i = 0; i < MAX_BINARY_OUTPUTS; i++) {
        out_of_service = Binary_Output_Out_Of_Service(i);
        if (!out_of_service) {
            binary_value = Binary_Output_Present_Value(i);
            polarity = Binary_Output_Polarity(i);
            if (polarity != POLARITY_NORMAL) {
                if (binary_value == BINARY_ACTIVE) {
                    binary_value = BINARY_INACTIVE;
                } else {
                    binary_value = BINARY_ACTIVE;
                }
            }
            if (binary_value == BINARY_ACTIVE) {
                if (i == 0) {
                    /* led_on(LED_2); */
                } else {
                    /* led_on(LED_3); */
                }
            } else {
                if (i == 0) {
                    /* led_off(LED_2); */
                } else {
                    /* led_off(LED_3); */
                }
            }
        }
    }
	if(flag_send_compelete == 1)
	{
		flag_send_compelete = 0;
//		retVal = Send_Write_Property_Request(1031,OBJECT_ANALOG_OUTPUT,1,PROP_PRESENT_VALUE,&object_value,8,-1);
		retVal = Send_Read_Property_Request_Address(&dest,480,OBJECT_BINARY_INPUT,1,PROP_PRESENT_VALUE,-1);
	}

    /* handle the communication timer */
    if (timer_interval_expired(&DCC_Timer)) {
        timer_interval_reset(&DCC_Timer);
        dcc_timer_seconds(DCC_CYCLE_SECONDS);
    }
    /* handle the messaging */
    pdu_len = datalink_receive(&src, &PDUBuffer[0], sizeof(PDUBuffer), 0);
    if (pdu_len) {
        npdu_handler(&src, &PDUBuffer[0], pdu_len);
    }
}
