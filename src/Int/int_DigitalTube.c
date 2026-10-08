#include "int_DigitalTube.h"
#include <STC89C5xRC.H>
// 数码管显示缓存
static u8 buffer[8];//数码管最多显示8位
//数字0~9的段选编码
static u8 s_digit_codes[11] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,0x80};//0~9和'.'的段选编码表



void DigitalTube_DisplaySingle(u8 position, u8 num_code){

    Delay1ms(1);
	P0 = 0x00;//清空P0

	P1 &=0xc7;//清空P1的中间三位
	position<<=3;
	P1 |=position;//选位
	//段选 ：P0
	P0=num_code; 
}

void DigitalTube_Devideintanddecimalpoint(f32 num){
    u8 cnt = 0;
    while(num>(u32)num){//有小数
        cnt++;
        num*=10;
    }
    num=(u32)num;
    DigitalTube_DisplayNum(num,cnt);
}

void DigitalTube_DisplayNum(u32 num, u8 decimal_point){
	u8 i;
	for(i=0;i<8;i++){
		buffer[i]=0x00;//每位清空
	}

	if(num==0){
		buffer[7]= s_digit_codes[0];//显示0
		return;
	}

	i=7;
	while(num>0){
        if(decimal_point==0){//有小数
            buffer[i]= s_digit_codes[num%10]+128;
        }else{//无小数
            buffer[i]= s_digit_codes[num%10];
        }
		    num/=10;
            decimal_point--;
		    i--;
	}
    if (decimal_point==0)
    {   
        buffer[i]= s_digit_codes[0]+128;
    }
    
}


void DigitalTube_Refresh(){
	u8 i;
	for(i=0;i<8;i++){
		DigitalTube_DisplaySingle(i, buffer[i]);
	}
}