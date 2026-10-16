#ifndef __INT_OLED_H__
#define __INT_OLED_H__
#include "Dri_Timer0.h"
#include "Util.h"
#include "Dri_IIC.h"
//设置设备地址
#define DEV_ADDR 0x78
#define CMD_TYPE 0x00
#define DATA_TYPE 0x40


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


#endif /* __INT_OLED_H__ */