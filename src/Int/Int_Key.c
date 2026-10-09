#include <STC89C5xRC.H>
#include "Util.h"


#define SW1 P42
#define SW2 P43
#define SW3 P32
#define SW4 P33

bit Int_Key_IsSW1Pressed()
{
    if (SW1 == 0) {
        Delay1ms(10); // 延时消抖
        if (SW1 == 0) {
            while (SW1 == 0); // 等待按键抬起
            return 1;
        }
    }
    return 0;
}

bit Int_Key_IsSW2Pressed()
{
    if (SW2 == 0) {
        Delay1ms(10); // 延时消抖
        if (SW2 == 0) {
            while (SW2 == 0); // 等待按键抬起
            return 1;
        }
    }
    return 0;
}

bit Int_Key_IsSW3Pressed()
{
    if (SW3 == 0) {
        Delay1ms(10); // 延时消抖
        if (SW3 == 0) {
            while (SW3 == 0); // 等待按键抬起
            return 1;
        }
    }
    return 0;
}

bit Int_Key_IsSW4Pressed()
{
    if (SW4 == 0) {
        Delay1ms(10); // 延时消抖
        if (SW4 == 0) {
            while (SW4 == 0); // 等待按键抬起
            return 1;
        }
    }
    return 0;
}
