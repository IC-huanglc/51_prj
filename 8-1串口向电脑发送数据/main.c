#include <REGX52.H>
#include "Delay1ms.h"
#include "LCD1602.h"
#include "Uart_Init.h"

unsigned char Sec = 0;

void main(){
	Uart_Init();
	
	while(1){
		Uart_SendByte(Sec);
		Sec++;
		Delay1ms(500);
	}
}