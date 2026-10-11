#include "Dri_Timer0.h"
#include <STC89C5xRC.H>
#include "Util.h"


void LED_Blink()
{
    static u16 count = 0;
    count++;
    if(count >= 500){
        count = 0;
        P00 = ~P00;
    }
}

void main(){
    Dri_Timer0_Init();//只要init就好了
    Dri_Timer0_RegisterCallback(LED_Blink);

    while(1){

    }
}