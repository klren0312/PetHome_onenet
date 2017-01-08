#include "jidianqi1.h"
volatile unsigned char  jdq1_value=0;



/*继电器GPIO配置 GPIOA PIN5*/
void JDQ_Init(void){
	GPIO_InitTypeDef GPIO_Structure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Structure.GPIO_Pin = GPIO_Pin_5;
	GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Structure);
}

/*分析平台下发的继电器控制命令*/
void JDQ_Cmdtl(void){
	/*平台控制命令“JDQ11“ 为打开继电器 */
	if((NULL !=strstr((const char *)usart2_cmd_buf,"JDQ11"))){
		JDQ_ON;
		jdq1_value = 1;
	}
	/*平台控制命令“JDQ12“ 为打开继电器 */
	if((NULL !=strstr((const char *)usart2_cmd_buf,"JDQ10"))){
		JDQ_OFF;
		jdq1_value = 0;
	}	
}

/*继电器操作函数，开启和关闭继电器*/
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

/*获得继电器当前状态*/
void JDQ_GetValue(void){
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_5)){
		jdq1_value = 1;
	}else{
		jdq1_value = 0;
	}
}





