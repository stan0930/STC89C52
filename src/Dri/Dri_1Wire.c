#include "Dri_1Wire.h"
#include <STC89C5xRC.H>
#define DQ P44
bit Dri_1Wire_Init()
{
    bit result;
    DQ = 0;
    Com_Util_Delay480us();
    DQ = 1;
    Com_Util_Delay60us();
    result = !DQ;
    Com_Util_Delay420us();
    return result;
}

void Dri_1Wire_WriteByte(u8 byte)
{
    u8 i;
    for (i = 0; i < 8; i++) {
        // 拉低总线
        DQ = 0;
        // 从低位发送
        DQ = byte & 0x1;
        byte >>= 1;

        // 延时50us
        Com_Util_Delay50us();
        // 释放总线
        DQ = 1;
    }

}


u8 Dri_1Wire_ReadByte()
{
    u8 byte;
    u8 i;
    for(i = 0;i < 8;i++){
      DQ = 0;
      //保持1us不用写
      DQ=1;
        byte>>=1;
      if(DQ ==1){
        byte |=0x80;
      }
      Com_Util_Delay50us();
    }
    return byte;
}