#include "Int_MatrixKey.h"
#include <STC89C5xRC.H>
#include "Int_DigitalTube.h"



u8 Int_MatrixKey_CheckKey() {
    u8 rows[4] = {0xFE,0xFD,0xFB,0xF7};
    u8 i,step,j;
    for (i = 0; i < 4; i++) 	
    {
        P2 = rows[i];
        for (j = 0; j < 4; j++){
            step = 0x10 << j ;
            if((P2&step)==0){
                Delay1ms(10);
                if((P2&step)==0){
                    while((P2&step)==0){Int_DigitalTube_Refresh();};
                    return 5+4*i+j;
                }
            }
        }
    }
    return 0;
}
