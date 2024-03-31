#include <REGX52.H>
#include "Delay1ms.h"
#include "LCD1602.h"
#include "Uart_Init.h"

unsigned char Sec = 0;

void main(){
	Uart_Init();
	
	while(1){
		
	}
}

void Uart_Rountine() interrupt 4{
	if(RI==1){
		P2 = SBUF;
		RI = 0;	//必须用软件复位
		Uart_SendByte(SBUF);
	}
}

/*串口中断函数模板
void Uart_Rountine() interrupt 4{
	if(RI==1){
		
		RI = 0;	//必须用软件复位
	}
}
*/