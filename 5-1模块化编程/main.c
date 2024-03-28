#include <REGX52.H>

#include "Nixie.h"

void main(){
	unsigned int cnt1 = 1;
	while(1){
		Nixie(cnt1, cnt1);
		if(cnt1 == 8)
			cnt1 = 0;
		else
			cnt1++;
	}
	
}
