#include "NeoPixel.h"
#include <stdlib.h>


int main(){
	
	//test();
	Init_Led();
	Init_GPIO();
	Init_PWM();
	
	
	Init_DMA();
//	Delay(1000);

	while(1)
	{
//	ClearALL_Led();
//	Show(1);
//	WriteLed(1, 1, 1, 0);
//	WriteLed(2, 1, 1, 0);
//	WriteLed(3, 1, 1, 0);
//	WriteLed(4, 1, 1, 0);
//	WriteLed(5, 1, 1, 0);
//	WriteLed(6, 1, 1, 0);
//	Show(1);
//	WriteLed(1, 0, 1, 0);
//	WriteLed(2, 0, 1, 0);
//	WriteLed(3, 0, 1, 0);
//	WriteLed(4, 0, 1, 0);
//	WriteLed(5, 0, 1, 0);
//	WriteLed(6, 0, 1, 0);
//	Show(1);
//	WriteLed(1, 0, 1, 1);
//	WriteLed(2, 0, 1, 1);
//	WriteLed(3, 0, 1, 1);
//	WriteLed(4, 0, 1, 1);
//	WriteLed(5, 0, 1, 1);
//	WriteLed(6, 0, 1, 1);
//	Show(1);
		ClearALL_Led();
		Delay(10000000);
		for(int i = 1; i <= 24; i++)
		{
			if(i <= 13)
				WriteLed(i, 0, 255, 0);
			else
				WriteLed(i, 0, 0, 255);
		}
		WriteLed(1, 0, 255, 125);
		WriteLed(13, 0, 255, 125);
		Show(180);
		
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 1, 0, 0);
		}
		Show(100);
		
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 0, 1, 0);
		}
		Show(100);
		
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 0, 0, 1);
		}
		Show(100);
		
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 1, 0, 1);
		}
		Show(100);
		
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 0, 1, 1);
		}
		Show(100);
		
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 1, 1, 1);
		}
		Show(100);
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 1, 0, 0);
			Show(5);
		}
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 0, 1, 0);
			Show(5);
		}
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 0, 0, 1);
			Show(5);
		}
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 1, 0, 1);
			Show(5);
		}
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 0, 1, 1);
			Show(5);
		}
		for(int i = 1; i <= 24; i++)
		{
			WriteLed(i, 1, 1, 0);
			Show(5);
		}
		
		WriteLed(1, 0, 1, 1);
		Show(5);
		for(int i = 24; i >= 2; i--)
		{
			WriteLed(26 - i, 0, 1, 0);
			WriteLed(i, 0, 0, 1);
			if(i == 13) WriteLed(i, 0, 1, 1);
			Show(5);
		}
		
		WriteLed(1, 1, 1, 0);
		Show(5);
		for(int i = 24; i >= 2; i--)
		{
			WriteLed(26 - i, 1, 0, 0);
			WriteLed(i, 0, 1, 1);
			if(i == 13) WriteLed(i, 1, 1, 0);
			Show(5);
		}
		
		WriteLed(1, 1, 0, 1);
		Show(5);
		for(int i = 24; i >= 2; i--)
		{
			WriteLed(26 - i, 0, 1, 0);
			WriteLed(i, 0, 0, 1);
			if(i == 13) WriteLed(i, 1, 0, 1);
			Show(5);
		}
		
		WriteLed(1, 0, 1, 1);
		Show(5);
		for(int i = 24; i >= 2; i--)
		{
			WriteLed(26 - i, 0, 1, 1);
			WriteLed(i, 0, 1, 1);
			if(i == 13) WriteLed(i, 0, 1, 1);
			Show(5);
		}
		
		WriteLed(1, 1, 1, 1);
		Show(5);
		for(int i = 24; i >= 2; i--)
		{
			WriteLed(26 - i, 1, 1, 1);
			WriteLed(i, 1, 1, 1);
			if(i == 13) WriteLed(i, 1, 1, 0);
			Show(5);
		}
		
		for(int i = 1; i <= 24; i++)
		{
			if(i % 2 == 1)
				WriteLed(i, 0, 255, 0);
			else
				WriteLed(i, 0, 0, 255);
		}
		Show(180);
		
		for(int i = 1; i <= 24; i++)
		{
			if(i % 2 == 1)
				WriteLed(i, 0, 0, 255);
			else
				WriteLed(i, 0, 255, 0);
		}
		Show(180);
		ClearALL_Led();
		
		WriteLed(1, 1, 1, 0);
		Show(5);
		for(int i = 24; i >= 2; i--)
		{
			WriteLed(26 - i, 1, 1, 0);
			WriteLed(i, 1, 1, 0);
			if(i == 13) WriteLed(i, 1, 1, 0);
			Show(5);
		}
	};
};
