#include <REGX52.H>
#include <INTRINS.H>

void Delayms(unsigned int value)		//@11.0592MHz
{
	unsigned char i, j;
	unsigned int k;
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
	while(1){
		P2 = 0xFE;
		Delayms(100);
		P2 = 0xFD;
		Delayms(100);
	}
}