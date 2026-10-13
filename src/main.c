#include <STC89C5xRC.H>
#include "Util.h"
#include "Dri_Uart.h"

void main(){
    char c;
    Dri_Uart_Init();
    while(1){
        if(Dri_UART_ReceiveChar(&c)){//一直循环不断的在检测s_buffer里有没有值
            if(c=='A'){
                P0=0x00;
                Dri_Uart_SendStr("OK:LED is on");
            }else if(c=='B'){
                P0=0xFF;
                Dri_Uart_SendStr("OK:LED is off");
            }else{
                Dri_Uart_SendStr("ERROR:Invalid command");
            }
        }
    }
}