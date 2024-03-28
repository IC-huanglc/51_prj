#include <INTRINS.H>

void Delay10us(unsigned char value)		//@11.0592MHz
{
	unsigned char i;

	while(value){
		_nop_();
		i = 25;
		while (--i);
		
		value--;
	}
}