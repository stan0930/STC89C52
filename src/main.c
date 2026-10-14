#include "Int_EEPROM.h"
#include "Int_MatrixLed.h"
#include "Dri_Timer0.h"


void main(void)
{
    u8 i=0;
    u8 picture[26] = {
        0xF8, 0x0A, 0xEC, 0xAF, 0xEC, 0x8A, 0xF8, 0x00,
        0x10, 0xF9, 0x97, 0xF1, 0x88, 0xAA, 0xFF, 0xAA,
        0x88, 0x00, 0x14, 0x0A, 0xF5, 0x92, 0x92, 0xF5,
        0x0A, 0x14
    };

    Int_EEPROM_WriteBytes(0x00, picture, 26);

    Dri_Timer0_Init();
    Int_MatrixLed_Init();

    Int_EEPROM_ReadBytes(0x00, picture, 26);

    while (1) {
        if (i >= 34) {
            i = 0;
        }

        if (i < 26) {
            Int_MatrixLed_DataLine(picture[i]);
        } else {
            Int_MatrixLed_DataLine(0);
        }

        i++;
        Delay1ms(200);
    }
}