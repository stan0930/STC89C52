#ifndef __INT_MATRIXKEY_H__
#define __INT_MATRIXKEY_H__

#include "Util.h"

/**
 * @brief 查看是否有矩阵按键被按下
 *
 * @return u8 返回被按下的按键编号，没有按键被按下返回0
 */
u8 Int_MatrixKey_CheckKey();

void Int_MatrixKey_Init();

void Int_MatrixKey_Off();
void Int_MatrixKey_Refresh(void);


#endif /* __INT_MATRIXKEY_H__ */
