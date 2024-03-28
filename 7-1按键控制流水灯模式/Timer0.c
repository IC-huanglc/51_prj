#include <REGX52.H>
//这是通过stc软件生成的代码
void Timer0Init(void)		//1毫秒@11.0592MHz
{
//	AUXR &= 0x7F;		//定时器时钟12T模式	//8051没有AUXR
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	
	ET0 = 1;	//Enable timer0
	EA = 1;		//Enable all
	PT0 = 0;
}