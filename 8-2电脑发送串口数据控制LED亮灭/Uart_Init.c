#include <REGX52.H>

void Uart_Init()		//4800bps@11.0592MHz
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率	//发送接收都使能
//	AUXR &= 0xBF;		//定时器1时钟为Fosc/12,即12T
//	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xF4;		//设定定时初值
	TH1 = 0xF4;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	
	//使能串口中断
	EA = 1;	//Enable all
	ES = 1;	//启动串口中断
}


void Uart_SendByte(unsigned char Byte){
	SBUF = Byte;
	while(TI==0);	//当发送中断未拉高，则一直等待
	TI = 0;			//当发送中断拉高，则必须用软件置为0
}

void Uart_RcvByte(unsigned char Byte){

}