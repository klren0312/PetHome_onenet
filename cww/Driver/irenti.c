#include "irenti.h"
volatile unsigned char  body_value=0;

void Body_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(Body_GPIO_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//感应高电平，所以选择下拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	
	GPIO_InitStructure.GPIO_Pin = Body_GPIO_PIN;
	GPIO_Init(Body_GPIO_PORT,&GPIO_InitStructure);
}

void Get_Bodystatus(void){
	if(GPIO_ReadInputDataBit(Body_GPIO_PORT,Body_GPIO_PIN)){
		TIM4->CCR1= 618;
		LED_BLUE_ON;
		printf("pet in the house");
		body_value=1;
	}else{
		LED_BLUE_OFF;
		TIM4->CCR1= 308;
		printf("pet out the house");
		body_value=0;
	}
}