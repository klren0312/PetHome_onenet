#ifndef __duoji_H
#define __duoji_H
#include "main.h"

extern volatile unsigned char  duoji_value;

void TIM4_Init(u16 arr,u16 psc);
void DUOJI_CmdCtl(void);
void DUOJI_GetValue(void);
#endif