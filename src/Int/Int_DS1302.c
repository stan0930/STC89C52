#include "Int_DS1302.h"
#define SCLK P37
#define CE P41
#define IO P40

void Int_DS1302_Init(void)
{
    SCLK = 0;
    CE = 0;
    IO = 0;
}

void Int_DS1302_WriteByte(u8 cmd_byte, u8 data_byte)//最低位开始取数
{
    u8 i;
    CE = 1;
    for ( i = 0; i < 8; i++)//命令字节cmd
    {
        IO=cmd_byte & 0x01;
        cmd_byte>>=1;
        SCLK=1;

        SCLK=0;
    }
    for ( i = 0; i < 8; i++)//数据字节data
    {   
        IO=data_byte & 0x01;
        data_byte>>=1;
        SCLK=1;

        SCLK=0;
    }
    
    
    CE = 0;
}

u8 Int_DS1302_ReadByte(u8 cmd_byte)//赋值8次，接收7次数据位，返回一个字节数据
{
    u8 i;
    u8 byte=0x00;
    CE = 1;
    for ( i = 0; i < 8; i++)//命令字节cmd
    {
        IO=cmd_byte & 0x01;
        cmd_byte>>=1;
        SCLK=1;

        SCLK=0;
    }

    if (IO==1)
    {
        byte |= 0x80;
    }
    

    for ( i = 0; i < 7; i++)//我们开始接收DS1302返回的数据字节data
    {
        SCLK=1;
        SCLK=0;
        byte>>=1;
        if(IO == 1){
            byte |= 0x80;
        }
    }
    CE = 0;
    return byte;
}

void Int_DS1302_SetDate(Struct_Date *p_st_date)
{   

    u8 byte;//把结构体里的信息写到这个byte里，再通过Int_DS1302_WriteByte()函数写入DS1302
    //关闭写保护
    Int_DS1302_WriteByte(WP,0x00);

    //设置秒

    //先把十位的数字录入再左移四位，后面再搞个位
    byte = (p_st_date->second %10) | ((p_st_date->second / 10)<<4);//精髓
    Int_DS1302_WriteByte(SECOND,byte);

    //设置分钟
    byte = (p_st_date->minute %10) | ((p_st_date->minute / 10)<<4);//精髓
    Int_DS1302_WriteByte(MINUTE,byte);

    //设置小时
    byte = (p_st_date->hour %10) | ((p_st_date->hour / 10)<<4);//24小时制
    Int_DS1302_WriteByte(HOUR,byte);

    //设置日期
    byte = (p_st_date->day %10) | ((p_st_date->day / 10)<<4);
    Int_DS1302_WriteByte(DAY,byte);

    //设置月份
    byte = (p_st_date->month %10) | ((p_st_date->month / 10)<<4);
    Int_DS1302_WriteByte(MONTH,byte);

    //设置星期
    byte = p_st_date->day_of_week;
    Int_DS1302_WriteByte(DAY_OF_WEEK,byte);

    //设置年份
    byte = (p_st_date->year %10) | ((p_st_date->year / 10)<<4);
    Int_DS1302_WriteByte(YEAR,byte);

    //开启写保护
    Int_DS1302_WriteByte(WP,0x80);
}

void Int_DS1302_GetDate(Struct_Date *p_st_date)
{   
    u8 byte;
    byte = Int_DS1302_ReadByte(SECOND+1);//返回秒
    p_st_date->second = (byte>>4)*10+(byte&0x0F);

    byte = Int_DS1302_ReadByte(MINUTE+1);//返回分钟
    p_st_date->minute = (byte>>4)*10+(byte&0x0F);

    byte = Int_DS1302_ReadByte(HOUR+1);//返回小时
    p_st_date->hour = (byte>>4)*10+(byte&0x0F);

    byte = Int_DS1302_ReadByte(DAY+1);//返回日期
    p_st_date->day = (byte>>4)*10+(byte&0x0F);

    byte = Int_DS1302_ReadByte(MONTH+1);//返回月份
    p_st_date->month = (byte>>4)*10+(byte&0x0F);
    
    byte = Int_DS1302_ReadByte(DAY_OF_WEEK+1);//返回星期
    p_st_date->day_of_week = byte;

    byte = Int_DS1302_ReadByte(YEAR+1);//返回年份
    p_st_date->year = (byte>>4)*10+(byte&0x0F);


}
