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
//	P2 = 0xFE;
	P2_0 = 1;
	while(1){
		if(P3_1 == 0){//P3_1 is key0s
			Delay1ms(20);
			while(P3_1 == 0);	//当按下key0，一直执行while循环，直到松手。就像打开或者关闭windows窗口一样。
			Delay1ms(20);
			P2_0 = ~P2_0;
		}
	}
}