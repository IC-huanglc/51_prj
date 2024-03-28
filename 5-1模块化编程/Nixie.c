#include <REGX52.H>
#include "Delay10us.h"

//array
unsigned char NixieTable[] ={
	0x3f,	//0
	0x06,	//1
	0x5b,	//2
	0x4f,	//3
	0x66,
	0x6d,
	0x7d,
	0x07,
	0x7f,
	0x6f,	//9
	0x77,	//a
	0x7c,	//b
	0x39,
	0x5e,
	0x79,
	0x71,	//f
	0x00	//null
};


void Nixie(unsigned char Location, Number){
	switch(Location){
		case 1: P2_4=1; P2_3=1; P2_2=1; break;
		case 2: P2_4=1; P2_3=1; P2_2=0; break;
		case 3: P2_4=1; P2_3=0; P2_2=1; break;
		case 4: P2_4=1; P2_3=0; P2_2=0; break;
		case 5: P2_4=0; P2_3=1; P2_2=1; break;
		case 6: P2_4=0; P2_3=1; P2_2=0; break;
		case 7: P2_4=0; P2_3=0; P2_2=1; break;
		case 8: P2_4=0; P2_3=0; P2_2=0; break;
	}
	
	P0 = NixieTable[Number];
	
	//消影，段选 位选 段选 位选，这个过程重复，但是在位选到段选的过程中，
	//位选还没关闭，段选就开始了，导致数码管串位。
	Delay10us(1);
	P0 = 0x00;
}