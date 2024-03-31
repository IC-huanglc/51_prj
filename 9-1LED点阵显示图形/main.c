#include <REGX52.H>
#include "Delay1ms.h"
sbit RCK = P3^5;	//74HC595 RCLK
sbit SCK = P3^6;	//74HC595 SCLK
sbit SER = P3^4;	//74HC595 SER

#define MATRIX_LED_PORT P0

void _74HC595_WriteByte(unsigned char Byte){
//	SER = Byte & 0x80;	//由于SER是1bit，Byte & 0x80是8bit，而当(Byte & 0x80)结果为非0时，SER结果为1'b1
	unsigned char i;
	for(i=0; i<8; i++){
		SER = Byte & (0x80 >> i);
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}

void MatrixLED_ShowColumn(unsigned char Column, Data){
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT = ~(0x80 >> Column);
	Delay1ms(1);
	MATRIX_LED_PORT = 0xFF;
	
}

void main(){
	SCK = 0;	//刚上电时，74HC595的SCLK为高电平，而SCLK的上升沿会寄存SER数据到74HC595中，故需要将其置零。
	RCK = 0;	//原理同上。RCLK上升沿时会并行输出8位数据。
	while(1){
		MatrixLED_ShowColumn(7, 0xaa);
	}
}