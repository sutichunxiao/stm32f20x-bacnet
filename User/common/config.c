#include "config.h"

void Open207_LEDInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	/*--------------------------------------------------------------------------------
	
	LED GPIO Config
	
	--------------------------------------------------------------------------------*/
	/* GPIOF Periph clock enable */
	RCC_AHB1PeriphClockCmd(Open_LED_GPIO_CLK, ENABLE);
	
	/* Configure PF6 PF7 PF8 PF9 in output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = Open_GPIO_Pin_LED1 | Open_GPIO_Pin_LED2
	 							  | Open_GPIO_Pin_LED3 | Open_GPIO_Pin_LED4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(Open_LED_GPIO, &GPIO_InitStructure);


}

void Open207_JOYSTICK_KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(Open_JOYSTICK_A_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd(Open_JOYSTICK_B_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd(Open_JOYSTICK_C_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd(Open_JOYSTICK_D_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd(Open_JOYSTICK_PRESS_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd(Open_USER_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd(Open_WAKEUP_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	//A
    GPIO_InitStructure.GPIO_Pin = Open_GPIO_Pin_A ;
	GPIO_Init(Open_JOYSTICK_A_PORT, &GPIO_InitStructure);	

	//B
    GPIO_InitStructure.GPIO_Pin = Open_GPIO_Pin_B ;
	GPIO_Init(Open_JOYSTICK_B_PORT, &GPIO_InitStructure);

	//C
    GPIO_InitStructure.GPIO_Pin = Open_GPIO_Pin_C ;
	GPIO_Init(Open_JOYSTICK_C_PORT, &GPIO_InitStructure);

	//D
    GPIO_InitStructure.GPIO_Pin = Open_GPIO_Pin_D ;
	GPIO_Init(Open_JOYSTICK_D_PORT, &GPIO_InitStructure);

	//PRESS
    GPIO_InitStructure.GPIO_Pin = Open_GPIO_Pin_PRESS ;
	GPIO_Init(Open_JOYSTICK_PRESS_PORT, &GPIO_InitStructure);

	//user(PB1) 
    GPIO_InitStructure.GPIO_Pin = Open_GPIO_Pin_USER ;
	GPIO_Init(Open_USER_PORT, &GPIO_InitStructure);	

	//wakeup(PA0)
    GPIO_InitStructure.GPIO_Pin = Open_GPIO_Pin_WAKEUP;
	GPIO_Init(Open_WAKEUP_PORT, &GPIO_InitStructure);	

}
