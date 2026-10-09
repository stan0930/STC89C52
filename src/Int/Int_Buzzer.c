#include "Util.h"
#include <STC89C5xRC.H>
#include "Int_MatrixKey.h"

#define BUZZER P46

void Int_Buzzer_Buzz()
{   
    u8 count = 100;
    while(count > 0){
        BUZZER = ~BUZZER;
        Delay1ms(1);
        count--;
    }
}