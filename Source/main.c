#include "NeoPixel.h"
#include <stdlib.h>

int main(){
	Init_GPIO();	
	Init_PWM();
	Init_DMA();
	while(1)
	{};
};
