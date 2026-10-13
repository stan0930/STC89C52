#ifndef __DRI_UART_H__
#define __DRI_UART_H__
#include "Util.h"

void Dri_Uart_Init(void);


/**
 * @brief 发送一个字符
 * 
 * @param c 要发送的字符
 */
void Dri_Uart_SendChar(char c);

void Dri_Uart_SendStr(char *str);

bit Dri_UART_ReceiveChar(char *c);//sbuf中的数据给到c

#endif /* __DRI_UART_H__ */