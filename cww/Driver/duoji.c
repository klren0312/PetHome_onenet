#include "duoji.h"
volatile unsigned char  duoji_value=0;

void TIM4_Init(u16 arr,u16 psc){
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = arr;
	TIM_TimeBaseStructure.TIM_Prescaler = psc;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OC1Init(TIM4,&TIM_OCInitStructure);
	
	TIM_ARRPreloadConfig(TIM4,ENABLE);
	TIM_Cmd(TIM4,ENABLE);
	TIM4->CCR1= 504;
}

//舵机收到平台命令
void DUOJI_CmdCtl(void){
	if((NULL != strstr((const char *)usart2_cmd_buf,"DUOJI1"))){
//		TIM_SetCompare1(TIM4,5);
		TIM4->CCR1= 308;
		duoji_value = 1;
	}
	if((NULL != strstr((const char *)usart2_cmd_buf,"DUOJI0"))){
		TIM4->CCR1= 618;
		duoji_value = 0;
	}
}

//获取舵机状态
void DUOJI_GetValue(void){
	if(duoji_value == 1){
		duoji_value = 1;
	}else{
		duoji_value = 0;
	}
	
}






















