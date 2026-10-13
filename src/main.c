#include <STC89C5xRC.H>
#include "Dri_Timer0.h"
#include <string.h>
#include "Util.h"
#include "Dri_Uart.h"

void main(){
    char str[16];
    Dri_Timer0_Init();
    Dri_Uart_Init();
    while(1){
        if(Dri_UART_ReceiveStr(str)){//一直循环不断的在检测str里有没有值
            if(strcmp(str,"on")==0){
                P0=0x00;
                Dri_Uart_SendStr("OK:LED is on");
            }else if(strcmp(str,"off")==0){
                P0=0xFF;
                Dri_Uart_SendStr("OK:LED is off");
            }else{
                Dri_Uart_SendStr("ERROR:Invalid command");
            }
        }
    }
}