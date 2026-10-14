#ifndef __INT_EEPROM_H__
#define __INT_EEPROM_H__
#include "Util.h"
#include "Dri_IIC.h"
#define DEV_ADDR 0xA0
#define PAGE_SIZE 16
//先向EEPROM写入点阵LED的“尚硅谷”三个字字模，再取出来显示在点阵LED上

//写（写多个字节）
/**
 * @brief 向EEPROM写入多个字节
 * 
 * @param address 字节地址
 * @param bytes 被写入数据的数组
 * @param len 写入字节的个数
 */
void Int_EEPROM_WriteBytes(u8 address, u8 bytes[], u8 len);





//读（读多个字节）
/**
 * @brief 读取多个字节的数据
 * 
 * @param address 伪写（设置字节的地址）
 * @param bytes 该数组保存读取到的数据
 * @param len 读取字节的个数
 */
void Int_EEPROM_ReadBytes(u8 address, u8 bytes[], u8 len);//只對外暴露Int_EEPROM_ReadBytes，因爲内部包含調用Int_EEPROM_WritePage


void Int_EEPROM_WritePage(u8 address, u8 bytes[], u8 len);


#endif /* __INT_EEPROM_H__ */