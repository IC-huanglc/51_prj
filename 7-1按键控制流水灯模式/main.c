#include <REGX52.H>
#include "Timer0.h"

//void Timer0_Init(){
////	TMOD = 0x01;	//GATE=0, C/T=0, M1, M0 = 0b0
////由于TMOD是不可位寻址的，故对TMOD操作会对TIMER1产生影响
////所以要对TMOD进行与或运算，不能影响其它位
//	
//	TMOD &= 0xF0;	//把TMOD低4bit清零，高4bit不变，timer1不变。
//	TMOD |= 0x01;	//设定timer0模式为mode 1
//	
//	TF0 = 0;	//Timer0 Flag = 0;
//	TR0 = 1;
//	
//	//每隔1us计数+1，总共计时65535us，如何计时1秒？
//	//64535离计数器溢出差值位1000us，即1ms。
////	TL0 = 64535%256 + 1;	//这个加1很重要	//这是在12M时钟下计算的
////	TH0 = 64535/256;
//	TL0 = 0x18;
//	TH0 = 0xFC;
//	
//	ET0 = 1;	//Enable timer0
//	EA = 1;		//Enable all
//	PT0 = 0;
//}

//中断服务函数

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	
	//由于计满之后timer0回到0，故需要重新赋值初值。
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	
	T0Count++;
	if(T0Count >= 1000){
		T0Count = 0;
		P2_0 = ~P2_0;	//DEBUG
	}
}
	
void main(){
	Timer0Init();
	
	while(1){
	
	}
}

#endif