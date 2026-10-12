#include "Int_Led.h"
#include "Dri_Timer0.h"
#include <STC89C5xRC.H>
#include "Util.h"

#define LED_EN P34

/* LED 接在 P0，低电平点亮；每 100 ms 移动一次。 */
static u8 s_led_index;
static u16 s_tick_count;

void Int_Led_Init(void)
{
    s_led_index = 0;
    s_tick_count = 0;
    LED_EN = 1;
    P0 = 0xFE;
    Dri_Timer0_RegisterCallback(Int_Led_Show);
}

void Int_Led_Show(void)
{
    s_tick_count++;
    if (s_tick_count >= 100) {
        s_tick_count = 0;
        s_led_index++;
        if (s_led_index >= 8) {
            s_led_index = 0;
        }
        P0 = (u8)~(1 << s_led_index);
    }
}
