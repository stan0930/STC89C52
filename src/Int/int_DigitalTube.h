#ifndef __INT_DIGITALTUBE_H__
#define __INT_DIGITALTUBE_H__

#include <STC89C5xRC.H>
#include "Util.h"

/**
 * @brief 数码管初始化方法
 *
 */
void Int_DigitalTube_Init();

/**
 * @brief 设置数码管要显示的数字
 *
 * @param num 要显示的数字
 */
void Int_DigitalTube_DisplayNum(u32 num);

/**
 * @brief 数码管刷新主程序，需要在循环中一直调用
 *
 */
void Int_DigitalTube_Refresh();

#endif /* __INT_DIGITALTUBE_H__ */
