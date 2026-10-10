#include <STC89C5xRC.H>
#define LED1 P00


void INT0_Init()
{
    // 打开中断总开关
    EA = 1;
    // 打开外部中断0开关
    EX0 = 1;
    // 配置外部中断为下降沿触发
    IT0 = 1;
    //当前程序只有一个，优先级可省略不配


    //中断服务程序
}

void main()
{
    INT0_Init();
    while(1){
        
    }


}

void INT0_Handler() interrupt 0
{   
    LED1 = ~LED1;
}
