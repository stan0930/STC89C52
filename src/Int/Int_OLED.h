#ifndef __INT_OLED_H__
#define __INT_OLED_H__
#include "Dri_Timer0.h"
#include "Util.h"
#include "Dri_IIC.h"
//设置设备地址
#define DEV_ADDR 0x78
#define CMD_TYPE 0x00
#define DATA_TYPE 0x40//


// 初始化OLED
void Int_OLED_Init(void);

//向SSD1315写入字节（命令）
void Int_OLED_WriteCmdBytes(u8 bytes[], u8 size);

//向SSD1315写入字节（显示的数据）
/**
 * @brief 向SSD1315写入字节（显示的数据）
 * 
 * @param bytes 要写入的字节数组
 * @param size 数据字节数
 */
void Int_OLED_WriteDataBytes(u8 bytes[], u8 size);

void Int_OLED_Clear(void);
/**
 * @brief 帮我们完成设置OLED显示指针位置的函数，发送IIC指令给OLED来设置起始位置
 * 
 * @param page 页地址范围（0-7）
 * @param column 列地址范围（0-127）
 */
void Int_OLED_SetPointer(u8 page,u8 column);
/**
 * @brief 在指定位置（x,y）显示字符串
 * 
 * @param x 横坐标
 * @param y 纵坐标
 * @param str 待展示字符串
 */
void Int_OLED_ShowStr(u8 x, u8 y, u8 *str);

void Int_OLED_ShowNum(u8 x, u8 y, long int num);

#endif /* __INT_OLED_H__ */