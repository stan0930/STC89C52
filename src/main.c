#include "Int_DigitalTube.h"
#include "Int_MatrixKey.h"
int main()
{
    u8 key_pressed = 0;
    Int_DigitalTube_Init();
    Int_DigitalTube_DisplayNum(key_pressed);
    while (1) {
        key_pressed = Int_MatrixKey_CheckKey();
        if (key_pressed) {
            Int_DigitalTube_DisplayNum(key_pressed);
        }

        Int_DigitalTube_Refresh();
    }
}
