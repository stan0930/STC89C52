#include "Int_MatrixLed.h"//点阵屏
#include "Int_MatrixKey.h"//流水灯
#include "Int_Led.h"//流水灯
#include "Int_DigitalTube.h"//数码管

#include "Dri_Timer0.h"
#include "Util.h"

void main(){
    u8 buffer[8] = {0x01,
                 0x02,
                 0x04,
                 0x08,
                 0x10,
                 0x20,
                 0x40,
                 0x80};
    Int_MatrixLed_To_Buffer(buffer);

    Dri_Timer0_Init();//初始化定时器0


    while(1){
        if(P42 == 0){
            Int_MatrixKey_Off();
            Int_MatrixLed_Off();
            Delay1ms(10);
            if(P42 == 0){
                while(P42 == 0);
                Int_Led_Init();
            }
        }else if(P43 == 0){
            Int_Led_Off();
            Int_MatrixLed_Off();
            Delay1ms(10);
            if(P43 == 0){
                while(P43 == 0);
                Int_MatrixKey_Init();
            }
        }else if(P32 == 0){
            Int_Led_Off();
            Int_MatrixKey_Off();
            Delay1ms(10);
            if(P32 == 0){
                while(P32 == 0);
                Int_MatrixLed_Init();
            }
        }
        Int_MatrixKey_Refresh(); // 只在数码管模式下检测矩阵键并刷新显示
            }
}

// void main(){
//     u8 picture[26] = {0xF8, 0x0A, 0xEC, 0xAF, 0xEC, 0x8A, 0xF8, 0x00,
//                   0x10, 0xF9, 0x97, 0xF1, 0x88, 0xAA, 0xFF, 0xAA,
//                   0x88, 0x00, 0x14, 0x0A, 0xF5, 0x92, 0x92, 0xF5,
//                   0x0A, 0x14};
    
//     Int_MatrixLed_Init();//Dri_Timer0_Init()  +  Dri_Timer0_RegisterCallback(Int_MatrixLed_Show)
//     while(1){
//         u8 i;
        
//         for(i=0;i<26;i++)
//         {
//             Int_MatrixLed_DataLine(picture[i]);
//             Delay1ms(100);
//         }


//     }
// }
