#include <STC89C5xRC.H>
#include "int_DigitalTube.h"

#define SMG_EN P36
#define LED_EN P34

void main(void)
{
    SMG_EN = 0;
    LED_EN = 0;

	DigitalTube_Devideintanddecimalpoint(114.514);

    while (1)
    {
        DigitalTube_Refresh();
    }
}
