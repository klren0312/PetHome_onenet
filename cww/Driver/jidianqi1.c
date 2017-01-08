#include "jidianqi1.h"
volatile unsigned char  jdq1_value=0;



/*�̵���GPIO���� GPIOA PIN5*/
void JDQ_Init(void){
	GPIO_InitTypeDef GPIO_Structure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Structure.GPIO_Pin = GPIO_Pin_5;
	GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Structure);
}

/*����ƽ̨�·��ļ̵�����������*/
void JDQ_Cmdtl(void){
	/*ƽ̨�������JDQ11�� Ϊ�򿪼̵��� */
	if((NULL !=strstr((const char *)usart2_cmd_buf,"JDQ11"))){
		JDQ_ON;
		jdq1_value = 1;
	}
	/*ƽ̨�������JDQ12�� Ϊ�򿪼̵��� */
	if((NULL !=strstr((const char *)usart2_cmd_buf,"JDQ10"))){
		JDQ_OFF;
		jdq1_value = 0;
	}	
}

/*�̵������������������͹رռ̵���*/
void JDQ_Switch(const uint8_t statu,const uint8_t mode){
	if(statu){
		JDQ_OFF;
		
		if(mode&0x01){
			JDQ_ON;
		}
	}else{
		if(mode&0x01){
			JDQ_OFF;
		}
	}
}

/*��ü̵�����ǰ״̬*/
void JDQ_GetValue(void){
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_5)){
		jdq1_value = 1;
	}else{
		jdq1_value = 0;
	}
}





