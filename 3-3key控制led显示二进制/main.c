#include <REGX52.H>
#include <INTRINS.H>
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
	unsigned char LEDNum = 0;//char is 8bit, 0~255
	
	while(1){
		if(P3_1 == 0){
			Delay1ms(20);
			while(P3_1 == 0) ;
			Delay1ms(20);
			
			LEDNum++;
			P2 = ~LEDNum;
		}
	}
}