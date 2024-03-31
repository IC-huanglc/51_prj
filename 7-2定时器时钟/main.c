#include <REGX52.H>
#include "Delay1ms.h"
#include "LCD1602.h"
#include "Timer0.h"

static unsigned char Sec  = 00;
static unsigned char Min  = 53;
static unsigned char Hour = 19;

void main(){
	LCD_Init();
	Timer0Init();
	
	LCD_ShowString(1, 1, "Clock:");
	while(1){
		//因为LCD_ShowNum函数执行时间比较长，而中断函数中最好不要执行时间过长的任务。
		LCD_ShowNum(2, 1, Hour, 2);
		LCD_ShowNum(2, 4, Min, 2);
		LCD_ShowNum(2, 7, Sec, 2);
		LCD_ShowString(2, 1, "  :  :");
	}
}

//Timer0 Interrupt function
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;		//set initial value, for 1ms @ 11.0592MhZ
	TH0 = 0xFC;		//set initial value
	
	T0Count++;
	if(T0Count >= 1000){	//1000ms=1s
		T0Count = 0;
		Sec++;
		if(Sec >= 60){	//等于60的一瞬间就清零
			Sec = 0;
			Min++;
			if(Min >= 60){	//等于60的一瞬间就清零
				Min = 0;
				Hour++;
				if(Hour >= 24){
					Hour = 0;
				}
			}
		}
	}
}