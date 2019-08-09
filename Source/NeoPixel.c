#include "NeoPixel.h"

Status Init_Clock()
{	//Co the set clock nguon bang file system_stm32f10x.c (._.) 
	//RCC_DeInit();
	//RCC_HSEConfig(RCC_HSE_ON);
	//while(RCC_WaitForHSEStartUp == ERROR){};
	//RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE);
	//RCC_HSICmd(DISABLE);
	return Success;
}

Status Init_GPIO()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	//Deinit GPIO
	GPIO_DeInit(GPIOC);
	
	//Init GPIO
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	return Success;
};

uint32_t GetClockOSC()
{
	RCC_ClocksTypeDef ClockSource;
	RCC_GetClocksFreq(&ClockSource);
	return ClockSource.PCLK2_Frequency;
}

Status Init_PWM()
{
	TIM_DeInit(TIM4);
	GPIO_DeInit(GPIOB);
	
	GPIO_InitTypeDef WS2812;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	///init B0.
	WS2812.GPIO_Pin = GPIO_Pin_8;
	WS2812.GPIO_Mode = GPIO_Mode_AF_PP;
	WS2812.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&WS2812);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	TIM_BaseStruct.TIM_Prescaler = 0; // 8 Mhz
  TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_BaseStruct.TIM_Period = 19; /* 400Hz PWM */
  TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_BaseStruct.TIM_RepetitionCounter = 0;
  TIM_TimeBaseInit(TIM4, &TIM_BaseStruct);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
  
	TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_Low;
	
	TIM_OC3Init(TIM4, &TIM_OCStruct);
	
	TIM_CtrlPWMOutputs(TIM4, ENABLE);
	
	TIM_DMAConfig(TIM4, TIM_DMABase_CCR3, TIM_DMABurstLength_1Transfer);
	TIM_DMACmd(TIM4, TIM_DMA_Update, ENABLE);
	
	TIM_Cmd(TIM4, ENABLE);
	
	return Success;
}

void test(){
	
	for(int i = 0; i < 24; i++)
	{
		if(i < 15)
			a[i] = 0x000D0000;
		else
			a[i] = 0x00060000;
	}
	a[24] = 0;
}

void test2(){
	a[0] = 0x00060000; //
	a[1] = 0x000D0000; //
	a[2] = 0x00060000;
	a[3] = 0x000D0000; //
	a[4] = 0x00060000;//
	a[5] = 0x000D0000;
	a[6] = 0x00060000;
	a[7] = 0x000D0000;
	a[8] = 0x00060000; //
	a[9] = 0x000D0000; //
	a[10] = 0x00060000;
	a[11] = 0x000D0000; //
	a[12] = 0x00060000;//
	a[13] = 0x000D0000;
	a[14] = 0x00060000;
	a[15] = 0x000D0000;
	a[16] = 0x00060000; //
	a[17] = 0x000D0000; //
	a[18] = 0x00060000;
	a[19] = 0x000D0000; //
	a[20] = 0x00060000;//
	a[21] = 0x000D0000;
	a[22] = 0x00060000;
	a[23] = 0x000D0000;
	a[576] = 0;
	
}

Status WriteLed(int Led, uint8_t Green, uint8_t Red, uint8_t Blue)
{
	switch(Led)
	{
		case 9: //1
			n = 50;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 8: //2
			n = 74;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 7: //3
			n = 98;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 6: //4
			n = 122;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 5: //5
			n = 146;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 4: //6
			n = 170;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 3: //7
			n = 194;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 2: //8
			n = 218;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 1: //9
			n = 242;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 24: //10
			n = 266;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 23: //11
			n = 290;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 22: //12
			n = 314;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 21: //13
			n = 338;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 20: //14
			n = 362;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 19: //15
			n = 386;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 18: //16
			n = 410;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 17: //17
			n = 434;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 16: //18
			n = 458;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 15: //19
			n = 482;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 14: //20
			n = 506;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 13: //21
			n = 530;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 12: //22
			n = 554;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 11: //23
			n = 578;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
		case 10: //24
			n = 602;
			for(uint8_t i = 0; i <= 7; i++)
			{
					if(Get_Bit(Green, i)) a[n + i] = 0x000D0000; else a[n + i] = 0x00060000;
					if(Get_Bit(Red, i)) a[n + i + 8] = 0x000D0000; else a[n + i + 8] = 0x00060000;
					if(Get_Bit(Blue, i)) a[n + i +16] = 0x000D0000; else a[n + i + 16] = 0x00060000;
			}
			break;
	}
	return Success;
};

Status Show(uint32_t time){
	//Delay(1000000);
	DMA1_Channel5->CCR |= DMA_CCR1_EN;
	Delay(time*100000);
	DMA1_Channel5->CCR &= (uint16_t)(~DMA_CCR1_EN);
	return Success;
}
Status ClearALL_Led()
{
	for(int i = 50; i < Element; i++)
	{
		a[i] = 0x00060000;
	}
	Delay(500);
	Show(10);
	return Success;
};

Status Init_Led()
{
	for(int i = 50; i < Element; i++)
	{
		a[i] = 0x00060000;
	}
	Delay(5000);
	return Success;
};

Status Init_DMA()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); //RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	DMA_DeInit(DMA1_Channel5);//DMA_DeInit(DMA1_Channel1);
	DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)a;
	DMA_InitStruct.DMA_MemoryBaseAddr = (uint32_t)&TIM4->DMAR;
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralSRC;//DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStruct.DMA_BufferSize = Element*2;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Enable;//DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Disable;//DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; //DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStruct.DMA_Mode = DMA_Mode_Circular;//DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStruct.DMA_Priority = DMA_Priority_Medium;//DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	DMA_InitStruct.DMA_M2M = DMA_M2M_Enable;//DMA_InitStructure.DMA_M2M = DMA_M2M_Enable;
	DMA_ITConfig(DMA1_Channel5, DMA_IT_TC, ENABLE);
	DMA_Init(DMA1_Channel5, &DMA_InitStruct);
	//DMA_Cmd(DMA1_Channel5, ENABLE);
	
	NVIC_InitTypeDef NVIC_InitStructure;
//Enable DMA1 channel IRQ Channel */
NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel5_IRQn;
NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
NVIC_Init(&NVIC_InitStructure);
	return Success;
}

void DMA1_Channel5_IRQHandler(void)
{
  //Test on DMA1 Channel1 Transfer Complete interrupt
  if(DMA_GetITStatus(DMA1_IT_TC5))
  {
   //Clear DMA1 Channel1 Half Transfer, Transfer Complete and Global interrupt pending bits
    DMA_ClearITPendingBit(DMA1_IT_TC5);
  }
}

Status SendBit_WS2812B(uint16_t value)
{
	TIM4->CCR3 = value;
	return Success;
}
