#ifndef _CONFIG_H
#define _CONFIG_H

//#include <stdio.h>
#include "stm32f2xx.h"


/**
 * @brief connected to USART1
 */
/*--------------------USART----------------------------*/
//#define OpenUSART1
//#define OpenUSART2
#define OpenUART4
//#define OpenUART4
//#define OpenUART5
//#define OpenUSART6
/*--------------------SPI------------------------------*/
//#define OpenSPI1
#define OpenSPI2
//#define OpenSPI3
#define Open207_TOUTH_SPI2

/*--------------------I2C------------------------------*/
#define OpenI2C1
//#define OpenI2C2
//#define OpenI2C3
/*--------------------CAN-----------------------------*/
#define OpenCAN1
//#define OpenCAN2

/*--------------------LED-----------------------------*/
#define Open_LED_GPIO_CLK							RCC_AHB1Periph_GPIOB
#define Open_LED_GPIO								  GPIOB

#define Open_GPIO_Pin_LED1							GPIO_Pin_0
#define Open_GPIO_Pin_LED2							GPIO_Pin_1
#define Open_GPIO_Pin_LED3							GPIO_Pin_2
#define Open_GPIO_Pin_LED4							GPIO_Pin_3

/*--------------------JOYSTICK-----------------------------*/
//A(PB15)  B(PD9)  C(PD11)  D(PD13)  PRESS(PD15)
#define  Open_JOYSTICK_A_CLK						RCC_AHB1Periph_GPIOC 
#define  Open_JOYSTICK_A_PORT						GPIOC
#define  Open_GPIO_Pin_A              	GPIO_Pin_4

#define  Open_JOYSTICK_B_CLK						RCC_AHB1Periph_GPIOC
#define  Open_JOYSTICK_B_PORT						GPIOC
#define  Open_GPIO_Pin_B              	GPIO_Pin_5

#define  Open_JOYSTICK_C_CLK						RCC_AHB1Periph_GPIOC
#define  Open_JOYSTICK_C_PORT						GPIOC
#define  Open_GPIO_Pin_C              	GPIO_Pin_6


#define  Open_JOYSTICK_D_CLK						RCC_AHB1Periph_GPIOC
#define  Open_JOYSTICK_D_PORT						GPIOC  
#define  Open_GPIO_Pin_D              	GPIO_Pin_7

#define  Open_JOYSTICK_PRESS_CLK				RCC_AHB1Periph_GPIOC
#define  Open_JOYSTICK_PRESS_PORT				GPIOC
#define  Open_GPIO_Pin_PRESS            GPIO_Pin_13



#define Open_USER_CLK								    RCC_AHB1Periph_GPIOA    
#define Open_USER_PORT							    GPIOA	
#define Open_GPIO_Pin_USER					    GPIO_Pin_1

#define Open_WAKEUP_CLK						    	RCC_AHB1Periph_GPIOA    
#define Open_WAKEUP_PORT					    	GPIOA	
#define Open_GPIO_Pin_WAKEUP				    GPIO_Pin_0


/*----------------------------------------------------*/

#ifdef OpenUSART1  
	#define Open205R_USARTx                        	USART1
	
	#define Open205R_USARTx_CLK                    	RCC_APB2Periph_USART1
	
	#define Open205R_USARTx_TX_PIN                 	GPIO_Pin_9
	#define Open205R_USARTx_TX_GPIO_PORT           	GPIOA
	#define Open205R_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open205R_USARTx_TX_SOURCE              	GPIO_PinSource9
	#define Open205R_USARTx_TX_AF                  	GPIO_AF_USART1
	
	#define Open205R_USARTx_RX_PIN                 	GPIO_Pin_10
	#define Open205R_USARTx_RX_GPIO_PORT           	GPIOA
	#define Open205R_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open205R_USARTx_RX_SOURCE              	GPIO_PinSource10
	#define Open205R_USARTx_RX_AF                  	GPIO_AF_USART1
	
	#define Open205R_USARTx_CTS_PIN                 GPIO_Pin_11
	#define Open205R_USARTx_CTS_GPIO_PORT           GPIOA
	#define Open205R_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Open205R_USARTx_CTS_SOURCE              GPIO_PinSource11
	#define Open205R_USARTx_CTS_AF                  GPIO_AF_USART1
	
	#define Open205R_USARTx_RTS_PIN                 GPIO_Pin_12
	#define Open205R_USARTx_RTS_GPIO_PORT           GPIOA
	#define Open205R_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Open205R_USARTx_RTS_SOURCE              GPIO_PinSource12
	#define Open205R_USARTx_RTS_AF                  GPIO_AF_USART1
	
	#define Open205R_USARTx_IRQn                   	USART1_IRQn
#endif

#ifdef OpenUSART2
	#define Open205R_USARTx                        	USART2
	#define Open205R_USARTx_CLK                    	RCC_APB1Periph_USART2
	
	#define Open205R_USARTx_TX_PIN                 	GPIO_Pin_2
	#define Open205R_USARTx_TX_GPIO_PORT           	GPIOA
	#define Open205R_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open205R_USARTx_TX_SOURCE              	GPIO_PinSource2
	#define Open205R_USARTx_TX_AF                  	GPIO_AF_USART2
	
	
	#define Open205R_USARTx_RX_PIN                 	GPIO_Pin_3
	#define Open205R_USARTx_RX_GPIO_PORT           	GPIOA
	#define Open205R_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open205R_USARTx_RX_SOURCE              	GPIO_PinSource3
	#define Open205R_USARTx_RX_AF                  	GPIO_AF_USART2
	
	#define Open205R_USARTx_CTS_PIN                 GPIO_Pin_3
	#define Open205R_USARTx_CTS_GPIO_PORT           GPIOD
	#define Open205R_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define Open205R_USARTx_CTS_SOURCE              GPIO_PinSource3
	#define Open205R_USARTx_CTS_AF                  GPIO_AF_USART2
	
	#define Open205R_USARTx_RTS_PIN                 GPIO_Pin_4
	#define Open205R_USARTx_RTS_GPIO_PORT           GPIOD
	#define Open205R_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define Open205R_USARTx_RTS_SOURCE              GPIO_PinSource4
	#define Open205R_USARTx_RTS_AF                  GPIO_AF_USART2
	
	#define Open205R_USARTx_IRQn                    USART2_IRQn
#endif

#ifdef OpenUSART3
	#define Open205R_USARTx                        	USART3
	#define Open205R_USARTx_CLK                    	RCC_APB1Periph_USART3
	
	#define Open205R_USARTx_TX_PIN                 	GPIO_Pin_10
	#define Open205R_USARTx_TX_GPIO_PORT           	GPIOC
	#define Open205R_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Open205R_USARTx_TX_SOURCE              	GPIO_PinSource10
	#define Open205R_USARTx_TX_AF                  	GPIO_AF_USART3
	
	
	#define Open205R_USARTx_RX_PIN                 	GPIO_Pin_11
	#define Open205R_USARTx_RX_GPIO_PORT           	GPIOC
	#define Open205R_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Open205R_USARTx_RX_SOURCE              	GPIO_PinSource11
	#define Open205R_USARTx_RX_AF                  	GPIO_AF_USART3
	
	#define Open205R_USARTx_CTS_PIN                 GPIO_Pin_13
	#define Open205R_USARTx_CTS_GPIO_PORT           GPIOB
	#define Open205R_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define Open205R_USARTx_CTS_SOURCE              GPIO_PinSource13
	#define Open205R_USARTx_CTS_AF                  GPIO_AF_USART3
	
	#define Open205R_USARTx_RTS_PIN                 GPIO_Pin_14
	#define Open205R_USARTx_RTS_GPIO_PORT           GPIOB
	#define Open205R_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define Open205R_USARTx_RTS_SOURCE              GPIO_PinSource14
	#define Open205R_USARTx_RTS_AF                  GPIO_AF_USART3
	
	#define Open205R_USARTx_IRQn                    USART3_IRQn
#endif
#ifdef OpenUART4
	#define Open205R_USARTx                        	UART4
	#define Open205R_USARTx_CLK                    	RCC_APB1Periph_UART4
	
	#define Open205R_USARTx_TX_PIN                 	GPIO_Pin_0
	#define Open205R_USARTx_TX_GPIO_PORT           	GPIOA
	#define Open205R_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open205R_USARTx_TX_SOURCE              	GPIO_PinSource0
	#define Open205R_USARTx_TX_AF                  	GPIO_AF_UART4
	
	
	#define Open205R_USARTx_RX_PIN                 	GPIO_Pin_1
	#define Open205R_USARTx_RX_GPIO_PORT           	GPIOA
	#define Open205R_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open205R_USARTx_RX_SOURCE              	GPIO_PinSource1
	#define Open205R_USARTx_RX_AF                  	GPIO_AF_UART4
	
	#define Open205R_USARTx_IRQn                    UART4_IRQn
#endif
#ifdef OpenUART5
	#define Open205R_USARTx                        	UART5
	#define Open205R_USARTx_CLK                    	RCC_APB1Periph_UART5
	
	#define Open205R_USARTx_TX_PIN                 	GPIO_Pin_12
	#define Open205R_USARTx_TX_GPIO_PORT           	GPIOC
	#define Open205R_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Open205R_USARTx_TX_SOURCE              	GPIO_PinSource12
	#define Open205R_USARTx_TX_AF                  	GPIO_AF_UART5
	
	
	#define Open205R_USARTx_RX_PIN                 	GPIO_Pin_2
	#define Open205R_USARTx_RX_GPIO_PORT           	GPIOD
	#define Open205R_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOD
	#define Open205R_USARTx_RX_SOURCE              	GPIO_PinSource2
	#define Open205R_USARTx_RX_AF                  	GPIO_AF_UART5
	
	#define Open205R_USARTx_IRQn                    UART5_IRQn
#endif


/* SPIx Communication boards Interface */
// SPI1 MISO (PA6)	MOSI(PA7)  CLK(PA5)
#ifdef OpenSPI1
	#define Open205R_SPIx                           SPI1

	#define Open205R_SPIx_CLK                       RCC_APB2Periph_SPI1
	#define Open205R_SPIx_IRQn                      SPI1_IRQn
	#define Open205R_SPIx_IRQHANDLER                SPI1_IRQHandler
	
	#define Open205R_SPIx_SCK_PIN                   GPIO_Pin_5
	#define Open205R_SPIx_SCK_GPIO_PORT             GPIOA
	#define Open205R_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOA
	#define Open205R_SPIx_SCK_SOURCE                GPIO_PinSource5
	#define Open205R_SPIx_SCK_AF                    GPIO_AF_SPI1
	
	#define Open205R_SPIx_MISO_PIN                  GPIO_Pin_6
	#define Open205R_SPIx_MISO_GPIO_PORT            GPIOA
	#define Open205R_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOA
	#define Open205R_SPIx_MISO_SOURCE               GPIO_PinSource6
	#define Open205R_SPIx_MISO_AF                   GPIO_AF_SPI1
	
	#define Open205R_SPIx_MOSI_PIN                  GPIO_Pin_7
	#define Open205R_SPIx_MOSI_GPIO_PORT            GPIOA
	#define Open205R_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOA
	#define Open205R_SPIx_MOSI_SOURCE               GPIO_PinSource7
	#define Open205R_SPIx_MOSI_AF                   GPIO_AF_SPI1
#endif
// SPI2 MISO (PB14)	MOSI(PB15)  CLK(PB13)
#ifdef OpenSPI2
	#define Open205R_SPIx                           SPI2

	#define Open205R_SPIx_CLK                       RCC_APB1Periph_SPI2
	#define Open205R_SPIx_IRQn                      SPI2_IRQn
	#define Open205R_SPIx_IRQHANDLER                SPI2_IRQHandler
	
	#define Open205R_SPIx_SCK_PIN                   GPIO_Pin_13
	#define Open205R_SPIx_SCK_GPIO_PORT             GPIOB
	#define Open205R_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
	#define Open205R_SPIx_SCK_SOURCE                GPIO_PinSource13
	#define Open205R_SPIx_SCK_AF                    GPIO_AF_SPI2
	
	#define Open205R_SPIx_MISO_PIN                  GPIO_Pin_14
	#define Open205R_SPIx_MISO_GPIO_PORT            GPIOB
	#define Open205R_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOB
	#define Open205R_SPIx_MISO_SOURCE               GPIO_PinSource14
	#define Open205R_SPIx_MISO_AF                   GPIO_AF_SPI2
	
	#define Open205R_SPIx_MOSI_PIN                  GPIO_Pin_15
	#define Open205R_SPIx_MOSI_GPIO_PORT            GPIOB
	#define Open205R_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
	#define Open205R_SPIx_MOSI_SOURCE               GPIO_PinSource15
	#define Open205R_SPIx_MOSI_AF                   GPIO_AF_SPI2
#endif
#ifdef OpenSPI3
	#define Open205R_SPIx                           SPI3

	#define Open205R_SPIx_CLK                       RCC_APB1Periph_SPI3
	#define Open205R_SPIx_IRQn                      SPI3_IRQn
	#define Open205R_SPIx_IRQHANDLER                SPI3_IRQHandler
	
	#define Open205R_SPIx_SCK_PIN                   GPIO_Pin_3
	#define Open205R_SPIx_SCK_GPIO_PORT             GPIOB
	#define Open205R_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
	#define Open205R_SPIx_SCK_SOURCE                GPIO_PinSource3
	#define Open205R_SPIx_SCK_AF                    GPIO_AF_SPI3
	
	#define Open205R_SPIx_MISO_PIN                  GPIO_Pin_4
	#define Open205R_SPIx_MISO_GPIO_PORT            GPIOB
	#define Open205R_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOB
	#define Open205R_SPIx_MISO_SOURCE               GPIO_PinSource4
	#define Open205R_SPIx_MISO_AF                   GPIO_AF_SPI3
	
	#define Open205R_SPIx_MOSI_PIN                  GPIO_Pin_5
	#define Open205R_SPIx_MOSI_GPIO_PORT            GPIOB
	#define Open205R_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
	#define Open205R_SPIx_MOSI_SOURCE               GPIO_PinSource5
	#define Open205R_SPIx_MOSI_AF                   GPIO_AF_SPI3
#endif

#define I2C_SPEED               100000
#define I2C_SLAVE_ADDRESS7      0x30
/**
 * @brief Definition for COM port1, connected to I2Cx
 */
#ifdef OpenI2C1
	#define Open205R_I2Cx                        	I2C1
	#define Open205R_I2Cx_CLK                    	RCC_APB1Periph_I2C1
	
	#define Open205R_I2Cx_SDA_PIN                 	GPIO_Pin_7
	#define Open205R_I2Cx_SDA_GPIO_PORT           	GPIOB
	#define Open205R_I2Cx_SDA_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Open205R_I2Cx_SDA_SOURCE              	GPIO_PinSource7
	#define Open205R_I2Cx_SDA_AF                  	GPIO_AF_I2C1
	
	#define Open205R_I2Cx_SCL_PIN                 	GPIO_Pin_8
	#define Open205R_I2Cx_SCL_GPIO_PORT           	GPIOB
	#define Open205R_I2Cx_SCL_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Open205R_I2Cx_SCL_SOURCE              	GPIO_PinSource8
	#define Open205R_I2Cx_SCL_AF                  	GPIO_AF_I2C1
#endif
#ifdef OpenI2C2
	#define Open205R_I2Cx                        	I2C2
	#define Open205R_I2Cx_CLK                    	RCC_APB1Periph_I2C2
	
	#define Open205R_I2Cx_SDA_PIN                 	GPIO_Pin_11
	#define Open205R_I2Cx_SDA_GPIO_PORT           	GPIOB
	#define Open205R_I2Cx_SDA_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Open205R_I2Cx_SDA_SOURCE              	GPIO_PinSource11
	#define Open205R_I2Cx_SDA_AF                  	GPIO_AF_I2C2
	
	#define Open205R_I2Cx_SCL_PIN                 	GPIO_Pin_10
	#define Open205R_I2Cx_SCL_GPIO_PORT           	GPIOB
	#define Open205R_I2Cx_SCL_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Open205R_I2Cx_SCL_SOURCE              	GPIO_PinSource10
	#define Open205R_I2Cx_SCL_AF                  	GPIO_AF_I2C2
#endif
#ifdef OpenI2C3
	#define Open205R_I2Cx                        	I2C3
	#define Open205R_I2Cx_CLK                    	RCC_APB1Periph_I2C3
	
	#define Open205R_I2Cx_SDA_PIN                 	GPIO_Pin_9
	#define Open205R_I2Cx_SDA_GPIO_PORT           	GPIOC
	#define Open205R_I2Cx_SDA_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Open205R_I2Cx_SDA_SOURCE              	GPIO_PinSource9
	#define Open205R_I2Cx_SDA_AF                  	GPIO_AF_I2C3
	
	#define Open205R_I2Cx_SCL_PIN                 	GPIO_Pin_8
	#define Open205R_I2Cx_SCL_GPIO_PORT           	GPIOA
	#define Open205R_I2Cx_SCL_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Open205R_I2Cx_SCL_SOURCE              	GPIO_PinSource8
	#define Open205R_I2Cx_SCL_AF                  	GPIO_AF_I2C3
#endif

#define I2Cx_SPEED               1000000
#define I2Cx_SLAVE_ADDRESS7      0x30

#ifdef  OpenCAN1
  #define Open205R_CANx                       CAN1
  #define Open205R_CAN_CLK                    RCC_APB1Periph_CAN1
  #define Open205R_CAN_RX_PIN                 GPIO_Pin_11
  #define Open205R_CAN_TX_PIN                 GPIO_Pin_12
  #define Open205R_CAN_GPIO_PORT              GPIOA
  #define Open205R_CAN_GPIO_CLK               RCC_AHB1Periph_GPIOA
  #define Open205R_CAN_AF_PORT                GPIO_AF_CAN1
  #define Open205R_CAN_RX_SOURCE              GPIO_PinSource11
  #define Open205R_CAN_TX_SOURCE              GPIO_PinSource12
#endif       
#ifdef OpenCAN2
  #define Open205R_CANx                       CAN2
  #define Open205R_CAN_CLK                    RCC_APB1Periph_CAN2
  #define Open205R_CAN_RX_PIN                 GPIO_Pin_5
  #define Open205R_CAN_TX_PIN                 GPIO_Pin_6
  #define Open205R_CAN_GPIO_PORT              GPIOB
  #define Open205R_CAN_GPIO_CLK               RCC_AHB1Periph_GPIOB
  #define Open205R_CAN_AF_PORT                GPIO_AF_CAN2
  #define Open205R_CAN_RX_SOURCE              GPIO_PinSource5
  #define Open205R_CAN_TX_SOURCE              GPIO_PinSource6    
#endif

/**
 * @brief Definition for LCD
 */
 /* Configure LCD pins: PB1->Reset and PB0->Back Light Control */

#ifdef Open207_TOUTH_SPI
	#define Open205R_TOUTH_SPI                           SPI1

	#define Open205R_TOUTH_SPI_CLK                       RCC_APB1Periph_SPI1
	#define Open205R_TOUTH_SPI_IRQn                      SPI1_IRQn
	#define Open205R_TOUTH_SPI_IRQHANDLER                SPI1_IRQHandler
	
	#define Open205R_TOUTH_SPI_SCK_PIN                   GPIO_Pin_3
	#define Open205R_TOUTH_SPI_SCK_GPIO_PORT             GPIOB
	#define Open205R_TOUTH_SPI_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
	#define Open205R_TOUTH_SPI_SCK_SOURCE                GPIO_PinSource3
	#define Open205R_TOUTH_SPI_SCK_AF                    GPIO_AF_SPI1
	
	#define Open205R_TOUTH_SPI_MISO_PIN                  GPIO_Pin_6
	#define Open205R_TOUTH_SPI_MISO_GPIO_PORT            GPIOA
	#define Open205R_TOUTH_SPI_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOA
	#define Open205R_TOUTH_SPI_MISO_SOURCE               GPIO_PinSource6
	#define Open205R_TOUTH_SPI_MISO_AF                   GPIO_AF_SPI1
	
	#define Open205R_TOUTH_SPI_MOSI_PIN                  GPIO_Pin_7
	#define Open205R_TOUTH_SPI_MOSI_GPIO_PORT            GPIOA
	#define Open205R_TOUTH_SPI_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOA
	#define Open205R_TOUTH_SPI_MOSI_SOURCE               GPIO_PinSource7
	#define Open205R_TOUTH_SPI_MOSI_AF                   GPIO_AF_SPI1
#endif


#define Open205R_LCD_BackLightControl_PIN		GPIO_Pin_4
#define Open205R_LCD_BackLightControl_PORT		GPIOC
#define Open205R_LCD_BackLightControl_CLK		RCC_AHB1Periph_GPIOC

// #define Open205R_LCD_Reset_PIN					GPIO_Pin_1
// #define Open205R_LCD_Reset_PORT					GPIOB
// #define Open205R_LCD_Reset_CLK					RCC_AHB1Periph_GPIOB

#define Open205R_LCD_CS_PIN					    GPIO_Pin_7
#define Open205R_LCD_CS_PORT					  GPIOB
#define Open205R_LCD_CS_CLK						  RCC_AHB1Periph_GPIOB

#define Open205R_TP_CS_PIN						  GPIO_Pin_5
#define Open205R_TP_CS_PORT						  GPIOC
#define Open205R_TP_CS_CLK						  RCC_AHB1Periph_GPIOC

#define Open205R_TP_IRQ_PIN						  GPIO_Pin_4
#define Open205R_TP_IRQ_PORT					  GPIOB
#define Open205R_TP_IRQ_CLK						  RCC_AHB1Periph_GPIOB


/* DCMI Communication boards Interface */

/**
 * @connected to I2C2
 */
 /* Configure I2C1 pins: PB10->SIOC and PB11->SIOD */ 
#define Open205R_SCCB                        	I2C2
#define Open205R_SCCB_CLK                    	RCC_APB1Periph_I2C2

#define Open205R_SCCB_SDA_PIN                 	GPIO_Pin_10
#define Open205R_SCCB_SDA_GPIO_PORT           	GPIOB
#define Open205R_SCCB_SDA_GPIO_CLK            	RCC_AHB1Periph_GPIOB
#define Open205R_SCCB_SDA_SOURCE              	GPIO_PinSource10
#define Open205R_SCCB_SDA_AF                  	GPIO_AF_I2C2

#define Open205R_SCCB_SCL_PIN                 	GPIO_Pin_11
#define Open205R_SCCB_SCL_GPIO_PORT           	GPIOB
#define Open205R_SCCB_SCL_GPIO_CLK            	RCC_AHB1Periph_GPIOB
#define Open205R_SCCB_SCL_SOURCE              	GPIO_PinSource11
#define Open205R_SCCB_SCL_AF                  	GPIO_AF_I2C2



/**
 * @connected to NRF24L01
 */
 /* Configure NRF24L01 pins: IRQ->PB14 and CSN->PB15  CE->PB13*/ 
 /*--------------------LED-----------------------------*/
#define Open205R_IRQ_GPIO_CLK							RCC_AHB1Periph_GPIOB
#define Open205R_IRQ_GPIO								 GPIOB
#define Open205R_GPIO_Pin_IRQ							GPIO_Pin_14


#define Open205R_CSN_GPIO_CLK							RCC_AHB1Periph_GPIOB
#define Open205R_CSN_GPIO								 GPIOB
#define Open205R_GPIO_Pin_CSN							GPIO_Pin_15

#define Open205R_CE_GPIO_CLK							RCC_AHB1Periph_GPIOB
#define Open205R_CE_GPIO								 GPIOB
#define Open205R_GPIO_Pin_CE							GPIO_Pin_13



void Open207_LEDInit(void);
void Open207_JOYSTICK_KEY_Init(void);


#endif	  /*_CONFIG_H*/

