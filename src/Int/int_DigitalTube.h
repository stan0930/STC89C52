#ifndef __INT_DIGITALTUBE_H__
#define __INT_DIGITALTUBE_H__

#include "Com_Util.h"

/**
 * @brief 内部方法，让数码管某一位显示特定数字
 * 
 * @param position 片选, 从左到右[0-7]
 * @param num_code 显示想要的数字编码
 */
void DigitalTube_DisplaySingle(u8 position, u8 num_code);
/**
 * @brief 清空并根据num设置buffer数组
 * 
 * @param num 要显示的数字
 * */
void DigitalTube_DisplayNum(u32 num, u8 decimal_point);
/**
 * @brief 刷新数码管显示
 * 
 * 
 */
void DigitalTube_Refresh();
/**
 * @brief 将浮点数拆分为整数和小数点位数，并调用DigitalTube_DisplayNum显示
 * 
 * @param num 
 */
void DigitalTube_Devideintanddecimalpoint(f32 num);


#endif /* __INT_DIGITALTUBE_H__ */