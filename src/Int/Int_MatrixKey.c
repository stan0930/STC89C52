#include "Int_MatrixKey.h"
#include <STC89C5xRC.H>
#include "Int_DigitalTube.h"
#include "Dri_Timer0.h"

static bit s_enabled = 0;//是否启用矩阵检测功能


u8 Int_MatrixKey_CheckKey() {//无循环，快速一遍扫描
    u8 rows[4] = {0xFE,0xFD,0xFB,0xF7};
    u8 i,step,j;
    for (i = 0; i < 4; i++) 	
    {
        P2 = rows[i];
        for (j = 0; j < 4; j++){
            step = 0x10 << j ;
            if((P2&step)==0){//→ 确认按下
                Delay1ms(10);//→ 消抖
                if((P2&step)==0){//→ 消抖
                    while((P2&step)==0){Int_DigitalTube_Refresh();};//→ 等待松手
                    return 5+4*i+j;//→ 返回按键编号
                }
            }
        }
    }
    return 0;
}

void Int_MatrixKey_Refresh()
{   
        u16 key;
        if (!s_enabled) return;
        key = Int_MatrixKey_CheckKey();
        if(key != 0){
            Int_DigitalTube_DisplayNum(key);
        }
        Int_DigitalTube_Refresh();
}
void Int_MatrixKey_Init()
{
    Int_DigitalTube_Init();
    // 按键检测由主循环调用，不注册到中断
    s_enabled = 1;

}

void Int_MatrixKey_Off()
{
    s_enabled = 0;
    Int_DigitalTube_Off();
}
