#include "Dri_Uart.h"
#include "Util.h"
#include "Dri_Timer0.h"
#include <STC89C5xRC.H>

static bit s_is_sending = 0;//0表示未在发送，1表示正在发送中
static char s_buffer[16];
static u8 s_index = 0;//接收数据的索引

static u8 s_idle_count = 0;//空闲计数器，用于检测数据是否接收完毕
static bit s_is_complete = 0;


void Dri_UART_Timer0Callback(){

    s_idle_count++;
    if(s_index > 0 && s_idle_count >= 10){
        s_is_complete = 1;
    }
}


/**
 * @brief 初始化UART串口
 * 
 */
void Dri_Uart_Init(void)
{
    //设置工作模式：8个数据位，1个停止位，无校验位，异步收发
    SM0 = 0;
    SM1 = 1;
//----------------------------------------------------------
    //设置波特率：9600
    PCON &=0x7F;   //SMOD=0
    //定时器1工作在8位自动重装模式
    TMOD &=0x0F;
    TMOD |=0x20;

    //设置定时器1的初值
    TH1 = 0xFD;   //253
    TL1 = 0xFD;

    //启动定时器1
    TR1 = 1;
//----------------------------------------------------------

    //串口接收相关配置
    REN = 1;
    //SM2控制位设置为0，表示接受数据时不校验数据帧的停止位。
    SM2 = 0;
//----------------------------------------------------------

    //使能总开关
    EA = 1;
    //开启UART串口中断
    ES = 1;
    //复位中断标志位
    RI = 0;
    TI = 0;

//----------------------------------------------------------
    
    //注册空闲检测函数
    Dri_Timer0_RegisterCallback(Dri_UART_Timer0Callback);
}
//发送数据只要向SBUF中写入数据即可，他会自动后面的流程
void Dri_Uart_SendChar(char c)
{   
    while(s_is_sending == 1);//很精妙
    s_is_sending = 1;
    SBUF = c;
}

void Dri_Uart_SendStr(char *str)
{
    while(*str != 0){ 
        Dri_Uart_SendChar(*str);
        str++;
    }
}

bit Dri_UART_ReceiveStr(char *str)
{
    if(s_is_complete == 1){//数据接收完成
        u8 i;
        for(i =0;i < s_index;i++){
            str[i] = s_buffer[i];
        }
        str[i] = '\0';
        s_is_complete = 0;
        s_index = 0;
        return 1;
    }
    return 0;
}

void Dri_UART_Handler() interrupt 4  //串口中断的中断号是4
{
    /* 检查接收中断标志位RI，如果为1，表示有一帧数据接收完成 */
    if (RI == 1) {//数据已经在SBUF中
        s_buffer[s_index++] = SBUF;
        s_idle_count = 0;
        RI = 0;
    }

    /* 检查发送中断标志位TI，如果为1，表示有一帧数据发送完成 */
    if (TI == 1) {
        s_is_sending = 0;
        TI = 0;
    }
}
