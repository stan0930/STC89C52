#include "Int_DigitalTube.h"
#include "Int_MatrixKey.h"
int main()
{
    u8 key_pressed = 0;
    Int_DigitalTube_Init();
    Int_DigitalTube_DisplayNum(key_pressed);
    while (1) {
        key_pressed = Int_MatrixKey_CheckKey();// 检查是否有按键被按下
        if (key_pressed) {
            Int_DigitalTube_DisplayNum(key_pressed);// 显示按键编号
        }

        Int_DigitalTube_Refresh();// 刷新数码管显示
    }
}
