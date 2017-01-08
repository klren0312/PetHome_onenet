#ifndef __IRENTI_H
#define __IRENTI_H

#include "main.h"
extern volatile unsigned char  body_value;
#define Body_GPIO_PORT GPIOA
#define Body_GPIO_PIN GPIO_Pin_4
#define Body_GPIO_CLK RCC_APB2Periph_GPIOA

void Body_Init(void);
void Get_Bodystatus(void);
#endif