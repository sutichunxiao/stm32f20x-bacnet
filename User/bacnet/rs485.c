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
* Module Description:
* Handle the configuration and operation of the RS485 bus.
**************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "hardware.h"
#include "timer.h"
#include "bits.h"
#include "fifo.h"
#include "rs485.h"


/* buffer for storing received bytes - size must be power of two */
 uint8_t Receive_Buffer_Data[512];
 FIFO_BUFFER Receive_Buffer;
/* amount of silence on the wire */
static struct etimer Silence_Timer;
/* baud rate */
static uint32_t Baud_Rate = 19200;

/* The minimum time after the end of the stop bit of the final octet of a */
/* received frame before a node may enable its EIA-485 driver: 40 bit times. */
/* At 9600 baud, 40 bit times would be about 4.166 milliseconds */
/* At 19200 baud, 40 bit times would be about 2.083 milliseconds */
/* At 38400 baud, 40 bit times would be about 1.041 milliseconds */
/* At 57600 baud, 40 bit times would be about 0.694 milliseconds */
/* At 76800 baud, 40 bit times would be about 0.520 milliseconds */
/* At 115200 baud, 40 bit times would be about 0.347 milliseconds */
/* 40 bits is 4 octets including a start and stop bit with each octet */
#define Tturnaround  (40UL)



extern unsigned char count;
int uart_bytes_send(unsigned char const *p,int len)
{
	int i = 0;
	if(count == 0)
	{
		USART_ITConfig(UART4,USART_IT_RXNE,DISABLE);
//		USART_ITConfig(UART4,USART_IT_IDLE,DISABLE);
		GPIO_WriteBit(GPIOB, GPIO_Pin_15, Bit_SET);
		while(i < len)
		{
			USART_SendData(UART4, (uint8_t) *(p+i));
			while (USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET)
			{}		
			i++;
			timer_elapsed_start(&Silence_Timer);
		}
		GPIO_WriteBit(GPIOB, GPIO_Pin_15, Bit_RESET);
//		while(i--)
//		{
//			__nop();
//		}
		timer_elapsed_start(&Silence_Timer);
		USART_ITConfig(UART4,USART_IT_RXNE,ENABLE);
//		USART_ITConfig(UART4,USART_IT_IDLE,ENABLE);
	}
	return i;
}

/*************************************************************************
* Description: Reset the silence on the wire timer.
* Returns: nothing
* Notes: none
**************************************************************************/
void rs485_silence_reset(
    void)
{
    timer_elapsed_start(&Silence_Timer);
}

/*************************************************************************
* Description: Determine the amount of silence on the wire from the timer.
* Returns: true if the amount of time has elapsed
* Notes: none
**************************************************************************/
bool rs485_silence_elapsed(
    uint32_t interval)
{
    return timer_elapsed_milliseconds(&Silence_Timer, interval);
}

/*************************************************************************
* Description: Baud rate determines turnaround time.
* Returns: amount of milliseconds
* Notes: none
**************************************************************************/
static uint16_t rs485_turnaround_time(
    void)
{
    /* delay after reception before transmitting - per MS/TP spec */
    /* wait a minimum  40 bit times since reception */
    /* at least 2 ms for errors: rounding, clock tick */
    return (2 + ((Tturnaround * 1000UL) / Baud_Rate));
}

/*************************************************************************
* Description: Use the silence timer to determine turnaround time.
* Returns: true if turnaround time has expired.
* Notes: none
**************************************************************************/
bool rs485_turnaround_elapsed(
    void)
{
    return timer_elapsed_milliseconds(&Silence_Timer, rs485_turnaround_time());
}


/*************************************************************************
* Description: Determines if an error occured while receiving
* Returns: true an error occurred.
* Notes: none
**************************************************************************/
bool rs485_receive_error(
    void)
{
    return false;
}

                                                                                                                                                                                                                     /*********************************************************************//**
 * @brief        USARTx interrupt handler sub-routine
 * @param[in]    None
 * @return         None
 **********************************************************************/
//void USART2_IRQHandler(
//    void)
//{
//    uint8_t data_byte;


//    if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) {
//        /* Read one byte from the receive data register */
//        data_byte = USART_ReceiveData(USART2);
//        (void) FIFO_Put(&Receive_Buffer, data_byte);
//    }
//}

/*************************************************************************
* DESCRIPTION: Return true if a byte is available
* RETURN:      true if a byte is available, with the byte in the parameter
* NOTES:       none
**************************************************************************/
extern char flag_uart;
bool rs485_byte_available(
    uint8_t * data_register)
{
    bool data_available = false;        /* return value */

    if (flag_uart == 1) {
        if (data_register) {
            *data_register = 0x55;
			if(0 == *data_register)
			{
				flag_uart = 0;
			}
			else
			{
				data_available = true;
			}
        }
        timer_elapsed_start(&Silence_Timer);
        
    }

    return data_available;
}

/*************************************************************************
* DESCRIPTION: Sends a byte of data
* RETURN:      nothing
* NOTES:       none
**************************************************************************/
void rs485_byte_send(
    uint8_t tx_byte)
{
//	GPIO_WriteBit(GPIOB, GPIO_Pin_15, SET);
//    USART_SendData(UART4, tx_byte);
//	while (USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET)
//	{}
//	GPIO_WriteBit(GPIOB, GPIO_Pin_15, RESET);
    timer_elapsed_start(&Silence_Timer);
}

/*************************************************************************
* Description: Determines if a byte in the USART has been shifted from
*   register
* Returns: true if the USART register is empty
* Notes: none
**************************************************************************/
bool rs485_byte_sent(
    void)
{
    return USART_GetFlagStatus(UART4, USART_FLAG_TXE);
}

/*************************************************************************
* Description: Determines if the entire frame is sent from USART FIFO
* Returns: true if the USART FIFO is empty
* Notes: none
**************************************************************************/
bool rs485_frame_sent(
    void)
{
    return USART_GetFlagStatus(UART4, USART_FLAG_TC);
}

/*************************************************************************
* DESCRIPTION: Send some data and wait until it is sent
* RETURN:      true if a collision or timeout occurred
* NOTES:       none
**************************************************************************/
void rs485_bytes_send(
    uint8_t * buffer,   /* data to send */
    uint16_t nbytes)
{       /* number of bytes of data */
    uint8_t tx_byte;

    while (nbytes) {
        /* Send the data byte */
        tx_byte = *buffer;
        /* Send one byte */
        USART_SendData(UART4, tx_byte);
        while (!rs485_byte_sent()) {
            /* do nothing - wait until Tx buffer is empty */
        }
        buffer++;
        nbytes--;
    }
    /* was the frame sent? */
    while (!rs485_frame_sent()) {
        /* do nothing - wait until the entire frame in the
           Transmit Shift Register has been shifted out */
    }
    timer_elapsed_start(&Silence_Timer);

    return;
}

/*************************************************************************
* Description: Configures the baud rate of the USART
* Returns: nothing
* Notes: none
**************************************************************************/
static void rs485_baud_rate_configure(
    void)
{
    USART_InitTypeDef USART_InitStructure;

    USART_InitStructure.USART_BaudRate = Baud_Rate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl =
        USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    /* Configure USARTx */
    USART_Init(USART2, &USART_InitStructure);
}

/*************************************************************************
* Description: Sets the baud rate to non-volatile storeage and configures USART
* Returns: true if a value baud rate was saved
* Notes: none
**************************************************************************/
bool rs485_baud_rate_set(
    uint32_t baud)
{
    bool valid = true;

    switch (baud) {
        case 9600:
        case 19200:
        case 38400:
        case 57600:
        case 76800:
        case 115200:
            Baud_Rate = baud;
            rs485_baud_rate_configure();
            break;
        default:
            valid = false;
            break;
    }

    return valid;
}

/*************************************************************************
* Description: Determines the baud rate in bps
* Returns: baud rate in bps
* Notes: none
**************************************************************************/
uint32_t rs485_baud_rate(
    void)
{
    return Baud_Rate;
}

/*************************************************************************
* Description: Enable the Request To Send (RTS) aka Transmit Enable pin
* Returns: nothing
* Notes: none
**************************************************************************/
void rs485_rts_enable(
    bool enable)
{
    if (enable) {
        GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET);
    } else {
        GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_RESET);
    }
}

/*************************************************************************
* Description: Initialize the room network USART
* Returns: nothing
* Notes: none
**************************************************************************/
void rs485_init(
    void)
{
//	FIFO_Init(&Receive_Buffer, &Receive_Buffer_Data[0],
//        (unsigned) sizeof(Receive_Buffer_Data));
    timer_elapsed_start(&Silence_Timer);
}
