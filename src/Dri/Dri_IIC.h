#ifndef __DRI_IIC_H__
#define __DRI_IIC_H__
#include <STC89C5xRC.H>
#include "Util.h"
#define SCL P17
#define SDA P16 



//每次封装完一个功能都把SCL拉低
//发送起始信号
void Dri_IIC_Start();

//发送一个字节
void Dri_IIC_SendByte(u8 byte);

//接收确认信号
bit Dri_IIC_ReceiveAck();

//接收一个字节
u8 Dri_IIC_ReceiveByte();

//发送一个确认信号
void Dri_IIC_SendAck(bit ack);
//发送结束信号
void Dri_IIC_Stop();

#endif /* __DRI_IIC_H__ */