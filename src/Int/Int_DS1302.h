#ifndef __INT_DS1302_H__
#define __INT_DS1302_H__
#include "Util.h"

#define SECOND      0x80
#define MINUTE      0x82
#define HOUR        0x84
#define DAY         0x86
#define MONTH       0x88
#define DAY_OF_WEEK 0x8A
#define YEAR        0x8C
#define WP          0x8E

typedef struct{
    u8 second;
    u8 minute;
    u8 hour;
    u8 day;
    u8 month;
    u8 year; 
    u8 day_of_week;
} Struct_Date;

void Int_DS1302_Init(void);
/**
 * @brief 写入一个字节到DS1302，先写入命令字节，再写入数据字节
 * 
 * @param cmd_byte 命令字节
 * @param data_byte 数据字节
 */
void Int_DS1302_WriteByte(u8 cmd_byte,u8 data_byte);

u8 Int_DS1302_ReadByte(u8 cmd_byte);

void Int_DS1302_SetDate(Struct_Date * p_st_date);

void Int_DS1302_GetDate(Struct_Date * p_st_date);

#endif /* __INT_DS1302_H__ */