#include <REGX52.H>
#include <INTRINS.H>

unsigned char LEDNum = 0;
//unsigned int  cnt = 0;

void Delay1ms(unsigned int value)		//@11.0592MHz
{
	unsigned char i, j;
	while(value){
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
		value--;
	}
}

void main(){
	P2 = ~0x01;
	while(1){
		if(P3_1 == 0){
			//Ïû¶¶
			Delay1ms(20);
			while(P3_1 == 0);
			Delay1ms(20);
			
			LEDNum++;
			if(LEDNum >= 8)
				LEDNum = 0;
		}
		else if(P3_0 == 0){
			//Ïû¶¶
			Delay1ms(20);
			while(P3_0 == 0);
			Delay1ms(20);
			
			if(LEDNum == 0)
				LEDNum = 7;
			else
				LEDNum--;
		}
						
		P2 = ~(0x01 << LEDNum);
	}
}