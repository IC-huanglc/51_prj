#ifndef __UART_INIT_H__
#define __UART_INIT_H__

void Uart_Init();	//4800bps@11.0592MHz
void Uart_SendByte(unsigned char Byte);
void Uart_RcvByte(unsigned char Byte);

#endif
