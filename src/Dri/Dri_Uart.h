#ifndef __DRI_UART_H__
#define __DRI_UART_H__
#include "Util.h"

void Dri_Uart_Init(void);

void Dri_Uart_SendChar(char c);

void Dri_Uart_SendStr(char *str);

bit Dri_UART_ReceiveStr(char *str);

#endif /* __DRI_UART_H__ */