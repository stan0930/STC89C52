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

void Int_OLED_WriteDataBytes(u8 bytes[], u8 size)
{
    u8 i;

    Dri_IIC_Start();

    Dri_IIC_SendByte(DEV_ADDR);
    Dri_IIC_ReceiveAck();

    Dri_IIC_SendByte(DATA_TYPE);
    Dri_IIC_ReceiveAck();

    for (i = 0; i < size; i++) {
        Dri_IIC_SendByte(bytes[i]);
        Dri_IIC_ReceiveAck();
    }

    Dri_IIC_Stop();
}

void Int_OLED_Clear(void)
{
    u8 cmd_bytes[3];
    u8 data_bytes[8] = {0};
    u8 i;

    /* 选择水平寻址，设置整个 128x64 显存范围。 */
    cmd_bytes[0] = 0x20; // 设置寻址模式
    cmd_bytes[1] = 0x00; // 水平寻址
    Int_OLED_WriteCmdBytes(cmd_bytes, 2);

    cmd_bytes[0] = 0x21; // 设置列地址范围
    cmd_bytes[1] = 0x00; // 起始列 0
    cmd_bytes[2] = 0x7F; // 结束列 127
    Int_OLED_WriteCmdBytes(cmd_bytes, 3);

    cmd_bytes[0] = 0x22; // 设置页地址范围
    cmd_bytes[1] = 0x00; // 起始页 0
    cmd_bytes[2] = 0x07; // 结束页 7
    Int_OLED_WriteCmdBytes(cmd_bytes, 3);

    /* 128 列 * 8 页，每次发送 8 个 0，共 1024 字节。 */
    for (i = 0; i < 128; i++) {
        Int_OLED_WriteDataBytes(data_bytes, 8);
    }

}
