#include "Int_MatrixLed.h"
#include "Dri_Timer0.h"
#include "Util.h"

// void main(){

//     u8 buffer[8] = {0x01,
//                  0x02,
//                  0x04,
//                  0x08,
//                  0x10,
//                  0x20,
//                  0x40,
//                  0x80};

//     //将buffer中的数据转换为点阵屏的格式
//     Int_MatrixLed_To_Buffer(buffer);
//     Int_MatrixLed_Init();

//     while(1);
// }

void main(){
    u8 picture[26] = {0xF8, 0x0A, 0xEC, 0xAF, 0xEC, 0x8A, 0xF8, 0x00,
                  0x10, 0xF9, 0x97, 0xF1, 0x88, 0xAA, 0xFF, 0xAA,
                  0x88, 0x00, 0x14, 0x0A, 0xF5, 0x92, 0x92, 0xF5,
                  0x0A, 0x14};
    
    Int_MatrixLed_Init();//Dri_Timer0_Init()  +  Dri_Timer0_RegisterCallback(Int_MatrixLed_Show)
    while(1){
        u8 i;
        
        for(i=0;i<26;i++)
        {
            Int_MatrixLed_DataLine(picture[i]);
            Delay1ms(100);
        }


    }
}