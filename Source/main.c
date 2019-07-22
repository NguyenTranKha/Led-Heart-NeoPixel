#include "NeoPixel.h"
#include <stdlib.h>

uint8_t __element;
#define NumberLed 24;

ws2812b NeoPixel[3];
ws2812b *NeoPixel_Pointer;

int main(){
	//Init_Clock();
	//All_Led = (ws2812b*)malloc(10*sizeof(ws2812b));
//	NeoPixel[0].Blue = 1;
//	NeoPixel[0].Red = 2;
//	NeoPixel[0].Green = 3;
//	
//	NeoPixel[1].Blue = 4;
//	NeoPixel[1].Red = 5;
//	NeoPixel[1].Green = 6;
//	
//	NeoPixel[2].Blue = 7;
//	NeoPixel[2].Red = 8;
//	NeoPixel[2].Green = 9;
//	
//	NeoPixel_Pointer = NeoPixel;
//	NeoPixel_Pointer += 1;
//	__element = NeoPixel_Pointer->Blue;
//	ClockOSCS = GetClockOSC(); //kiem tra tan so
//	ClockSystem = RCC_GetSYSCLKSource(); // kiem tra nguon clock HSE = 0x04, HSI 0x00, PLL = 0x08
	Delay();
	Init_GPIO();
	GPIO_WriteBit(GPIOB, GPIO_Pin_13, 1);
	Init_PWM();
	SendBit_WS2812B(0);
	Delay();
	//
	SendBit_WS2812B(11);
	
	ClockOSCS = GetClockOSC();
	//Delay();
	while(1)
	{
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		
////		SendBit_WS2812B(5);
////		
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
////		SendBit_WS2812B(2);
	
		//SendBit_WS2812B(2);
		//SendBit_WS2812B(5);
		//SendBit_WS2812B(2);
//		SendBit_WS2812B(5);
//		SendBit_WS2812B(2);
//		SendBit_WS2812B(5);
//		SendBit_WS2812B(2);
//		SendBit_WS2812B(5);
//		SendBit_WS2812B(2);
//		SendBit_WS2812B(5);
//		SendBit_WS2812B(2);
//		SendBit_WS2812B(5);
//		SendBit_WS2812B(2);
//		SendBit_WS2812B(5);
//		SendBit_WS2812B(2);
//		SendBit_WS2812B(5);
//		SendBit_WS2812B(2);
//		SendBit_WS2812B(5);
//		SendBit_WS2812B(2);
//		SendBit_WS2812B(5);
//		SendBit_WS2812B(5);
	}
	return 0;
};
