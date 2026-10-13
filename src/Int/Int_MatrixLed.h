#ifndef __INT_MATRIXLED_H__
#define __INT_MATRIXLED_H__
//使用定时中断（动态扫描）
#include "Dri_Timer0.h"
#include <STC89C5xRC.H>
#include "Util.h"
//初始化 1.（开启点阵屏）2.向定时中断注册函数Int_MatrixLed_Show
void Int_MatrixLed_Init();

void Int_MatrixLed_Off();



void Int_MatrixLed_To_Buffer(u8 *buffer);

void Int_MatrixLed_DataLine(u8 line);

#endif /* __INT_MATRIXLED_H__ */