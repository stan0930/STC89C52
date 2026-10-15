#include "Int_EEPROM.h"

void Int_EEPROM_WritePage(u8 address, u8 bytes[], u8 len)
{
    u8 i;
    // 发送起始信号
    Dri_IIC_Start();
    // 发送设备地址
    Dri_IIC_SendByte(DEV_ADDR);//一块EEPROM
    // 接收确认信息
    Dri_IIC_ReceiveAck();

    // 发送字节地址
    Dri_IIC_SendByte(address);//写入地址
    // 接收确认信息
    Dri_IIC_ReceiveAck();
    // 发送数据
    for (i = 0; i < len; i++)
    {
        Dri_IIC_SendByte(bytes[i]);
        // 接收确认信息
        Dri_IIC_ReceiveAck();
    }
    // 发送停止信号
    Dri_IIC_Stop();
}

// 不支持跨页写
// 得程序员来算当前页剩余位置的个数
void Int_EEPROM_WriteBytes(u8 address, u8 bytes[], u8 len)
{
    u8 i;

    while (len > 0)
    {
        // 计算当前页剩余的位置有多少个
        u8 page_remain = PAGE_SIZE - address % PAGE_SIZE;

        if (page_remain < len)
        { // 当前页的空间不够必须 跨页 再页写

            // 先写page_remain(使用页写)
            Int_EEPROM_WritePage(address, bytes, page_remain);

            len = len - page_remain;
            address = address + page_remain; // 跨页
            bytes = bytes + page_remain;     // ’尚硅谷‘数组也要跳过写完的个数
        }
        else
        { // 当前页的空间足够 page_remain>=len 页写

            // 使用页写(写入len个字节)
            Int_EEPROM_WritePage(address, bytes, len);
            len = 0;
        }
        Delay1ms(3); // 别忘了延时3ms给EEPROM内部自己写入
    }
}

void Int_EEPROM_ReadBytes(u8 address, u8 bytes[], u8 len)
{
    u8 i;
    bit ack;
    // 发送起始信号
    Dri_IIC_Start();
    // 发送设备地址（写标识：0）
    Dri_IIC_SendByte(DEV_ADDR); // 1010 0000
    // 接收确认信息
    ack = Dri_IIC_ReceiveAck();
    // 发送字节地址
    Dri_IIC_SendByte(address);
    // 接收确认信息
    ack = Dri_IIC_ReceiveAck();

    // 再次发起起始信号
    Dri_IIC_Start();
    // 发送设备地址（读标识）
    Dri_IIC_SendByte(DEV_ADDR + 1); // 1010 0001
    // 接收确认信息
    ack = Dri_IIC_ReceiveAck();
    // 读取EEPROM中的数据
    for (i = 0; i < len; i++)
    {
        bytes[i] = Dri_IIC_ReceiveByte();
        // 发送确认信息
        Dri_IIC_SendAck(i == len - 1 ? 1 : 0); // 最后一位发送1不接收了，其他位发送0
    }

    // 发送停止信号
    Dri_IIC_Stop();
}
