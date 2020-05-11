#ifndef _USART_H
#define _USART_H

#include <stdio.h>
#include "stm32f2xx.h"
//#include "config.h"


void USART_Configuration(void);
void USART_NVIC_Config(void);
int uart_bytes_send(unsigned char const *p,int len);
#endif /*_USART_H*/
