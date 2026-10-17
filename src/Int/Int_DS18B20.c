#include "Int_DS18B20.h"
#include "Util.h"
#include "Dri_1Wire.h"

char Int_DS18B20_GetTemperature(void)
{   

    u8 ls_byte;
    u8 ms_byte;
    //初始化
    Dri_1Wire_Init();
    //发送ROM命令
    Dri_1Wire_WriteByte(0xCC);
    //发送测温命令
    Dri_1Wire_WriteByte(0x44);
    Delay1ms(750);    //默认 12 位精度下，一次转换最长约 750ms。不能发送命令后马上就当作结果已经更新，否则可能读到上一次的数据，或上电初始值 85°C。


    //初始化
    Dri_1Wire_Init();
    //发送ROM命令
    Dri_1Wire_WriteByte(0xCC);
    //发送测温命令
    Dri_1Wire_WriteByte(0xBE);

    ls_byte = Dri_1Wire_ReadByte();
    ms_byte = Dri_1Wire_ReadByte();

    return (ls_byte >> 4) | (ms_byte << 4);

}