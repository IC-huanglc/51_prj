#include <REGX52.H>
#include "LCD1602.h"
#include "Delay10us.h"
#include "Delay1ms.h"

int result;
unsigned int sec = 0;
unsigned int min = 21;
unsigned int hour = 21;

void main(){
	result = 1+1;
	
	LCD_Init();
//	LCD_ShowChar(1, 1, 'A');	//字符用单引号表示

//	LCD_ShowString(1, 3, "Hello");	//字符串用双引号表示
//	
//	LCD_ShowNum(1, 9, result, 3);
//	
//	LCD_ShowSignedNum(1, 13, -66, 2);
//	
//	LCD_ShowHexNum(2, 1, 0xA8, 2);
//	
//	LCD_ShowBinNum(2, 4, 0xAA, 8);
	
	while(1){		
		sec++;
		if(sec >= 60){
			sec = 0;
			min++;
		}
		
		if(min >= 60){
			min = 0;
			hour++;
		}
		
		if(hour >= 24)
			hour = 0;
		
		Delay1ms(500);
		LCD_ShowNum(1,1, hour, 2);
		LCD_ShowChar(1, 3, ':');
		
		LCD_ShowNum(1,4, min, 2);
		LCD_ShowChar(1, 6, ':');
		
		LCD_ShowNum(1,7, sec, 2);
	}
}
