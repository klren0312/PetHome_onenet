#ifndef __JIDIANQI1_H
#define __JIDIANQI1_H
#include "main.h"

#define JDQ_ON GPIO_SetBits(GPIOA,GPIO_Pin_5)
#define JDQ_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_5)

#define  JDQ_1    0X01
#define  J_OFF  0
#define  J_ON   (!J_OFF)
extern volatile unsigned char  jdq1_value;


void JDQ_Init(void);
void JDQ_Cmdtl(void);
void JDQ_Switch(const uint8_t statu,const uint8_t mode);
void JDQ_GetValue(void);


#endif

