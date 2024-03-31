#include <REGX52.H>

void Timer1_Init(){
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20 ;		//设置定时器模式，双8位自动重装
}