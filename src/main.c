#include "Int_OLED.h"


// void main(void)
// {   
//     u8 i=0;
//     u8 picture[26] = {
//         0xF8, 0x0A, 0xEC, 0xAF, 0xEC, 0x8A, 0xF8, 0x00,
//         0x10, 0xF9, 0x97, 0xF1, 0x88, 0xAA, 0xFF, 0xAA,
//         0x88, 0x00, 0x14, 0x0A, 0xF5, 0x92, 0x92, 0xF5,
//         0x0A, 0x14
//     };

//     Int_EEPROM_WriteBytes(0x00, picture, 26);

//     Dri_Timer0_Init();
//     Int_MatrixLed_Init();

//     Int_EEPROM_ReadBytes(0x00, picture, 26);

//     while (1) {
//         if (i >= 34) {
//             i = 0;
//         }

//         if (i < 26) {
//             Int_MatrixLed_DataLine(picture[i]);
//         } else {
//             Int_MatrixLed_DataLine(0);
//         }

//         i++;
//         Delay1ms(200);
//     }
// }


void main(void)
{   
    u8 data_bytes[16] = {0xC0, 0x30, 0x08, 0x08, 0x08, 0x38, 0x00, 0x00,
                        0x07, 0x18, 0x20, 0x20, 0x22, 0x1E, 0x02, 0x00};
    u8 cmd_bytes[5];
    cmd_bytes[0] = 0x20; // 设置寻址模式
    cmd_bytes[1] = 0x02; // 页寻址模式
    //-----------------------------------------------------------------
    cmd_bytes[2] = 0xB0; // 页地址范围
    cmd_bytes[3] = 0x00; // 列地址范围
    cmd_bytes[4] = 0x10; // 列地址范围//这里规定配置列地址需要拆成两行来配置




    Int_OLED_Init();
    Int_OLED_Clear();
    Int_OLED_WriteCmdBytes(cmd_bytes, 5);//写入命令字节
    Int_OLED_WriteDataBytes(data_bytes, 8);//写G字母的上半部分
    cmd_bytes[2] = 0xB1; // 页地址范围//切换到下一页
    Int_OLED_WriteCmdBytes(cmd_bytes, 5);//写入命令字节
    Int_OLED_WriteDataBytes(data_bytes+8, 8);//写G字母的下半部分
    
    while (1) {
    }
    
}
