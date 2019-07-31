#include "NeoPixel.h"
#include <stdlib.h>

int main(){
	test();
	Init_GPIO();	
	Init_PWM();
	Init_DMA();
	while(1)
	{};
};
