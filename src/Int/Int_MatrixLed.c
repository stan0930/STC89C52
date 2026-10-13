#include "Int_MatrixLed.h"
#include "Util.h"
#include "Dri_Timer0.h"
#define LEDEN P34
#define SMGEN P36
#define DZPEN P35
//8位串行输入
#define SER P10
#define RCK P11
#define SCK P12

static u8 arr[8];

//点亮点阵屏
static void Int_MatrixLed_Show()
{
    static u8 i = 0;//表示被扫描的次数



    //行扫描
    if(i==0)
    {
        SER = 1;
    }else{
        SER = 0;
    }

    //SCK上升沿 把SER的数据写入到移位寄存器
    SCK=0;
    SCK=1;

    //RCK上升沿 把移位寄存器的数据写入到RCK
    RCK=0;
    RCK=1;

    //设置列的值
    P0 = ~arr[i];//因为点阵屏的列是共阴极，所以要取反

    //设置列的值
    i++;
    if(i>7){
        i=0;
    }
}


void Int_MatrixLed_Init(void)
{
    //开启点阵屏
    DZPEN = 0;
    //关闭led
    LEDEN = 0;
    //关闭数码管
    SMGEN = 1;
    //开启定时器
    //Dri_Timer0_Init();    main函数里有这里就不写

    //注册函数Int_MatrixLed_Show到定时器
    Dri_Timer0_RegisterCallback(Int_MatrixLed_Show);

}

void Int_MatrixLed_Off()
{
    //关闭点阵屏
    DZPEN = 1;
    //关闭led
    LEDEN = 0;
    //关闭数码管
    SMGEN = 1;
    //删除定时器0的回调函数
    Dri_Timer0_DeregisterCallback(Int_MatrixLed_Show);
}

//接收所有阴极的数据（P00-P07）八行数据
void Int_MatrixLed_To_Buffer(u8 *buffer)
{
    u8 i;
    for(i = 0; i < 8; i++)
    {
        arr[i] = buffer[i];
    }
}

//接收一行数据
void Int_MatrixLed_DataLine(u8 line)
{   
    //把数组前面的数据向后移动一个位置（把0位置清空）
    u8 i;
    for(i=7;i>0;i--)
    {
        arr[i]=arr[i-1];
    }

    arr[0]=line;//把最新的字节数据保存到数组的第一个位置

}

