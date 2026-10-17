#include "Int_DS18B20.h"
#include "Int_OLED.h"
#include "Util.h"
#include "Dri_1Wire.h"

void main(void)
{
    Int_OLED_Init();
    Int_OLED_Clear();

    while (1) {
    Int_OLED_ShowNum(0, 0, Int_DS18B20_GetTemperature());
    Delay1ms(500);
}
}

