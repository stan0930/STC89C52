#include "Int_OLED.h"

void Int_OLED_Init(void)
{
    u8 cmd_bytes[6];
    cmd_bytes[0] = 0xAE;//set display off
    //行重映射
    cmd_bytes[1] = 0xA1;//set segment re-map
    //列重映射
    cmd_bytes[2] = 0xC8;//set common output direction

    cmd_bytes[3] = 0x8D;
    cmd_bytes[4] = 0x14;
    cmd_bytes[5] = 0xAF;//set display on

    Int_OLED_WriteCmdBytes(cmd_bytes, 6);


}

void Int_OLED_WriteCmdBytes(u8 bytes[], u8 size)
{
    u8 i;

    //发送起始信息
    Dri_IIC_Start();
    //发送设备地址
    Dri_IIC_SendByte(DEV_ADDR);
    Dri_IIC_ReceiveAck();
    //发送字节类型（发送命令类型）
    Dri_IIC_SendByte(CMD_TYPE);
    Dri_IIC_ReceiveAck();
    //发送具体的命令
    for (i = 0; i < size; i++) {
        Dri_IIC_SendByte(bytes[i]);
        Dri_IIC_ReceiveAck();
    }

    Dri_IIC_Stop();

}
