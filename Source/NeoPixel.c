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
	
	//TIM_CtrlPWMOutputs(TIM4, ENABLE);
	
	TIM_DMAConfig(TIM4, TIM_DMABase_CCR3, TIM_DMABurstLength_1Transfer);
	TIM_DMACmd(TIM4, TIM_DMA_Update, ENABLE);
	
	TIM_Cmd(TIM4, ENABLE);
	
	return Success;
}

Status Init_DMA()
{	
	for(int i = 0; i <= 23; i++)
	{
		if(i < 20)
			a[i] = 13;
		else
			a[i] = 6;
	}
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); //RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	DMA_DeInit(DMA1_Channel5);//DMA_DeInit(DMA1_Channel1);
	DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)a;
	DMA_InitStruct.DMA_MemoryBaseAddr = (uint32_t)&TIM4->DMAR;
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralSRC;//DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStruct.DMA_BufferSize = 48;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Enable;//DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Disable;//DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; //DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStruct.DMA_Mode = DMA_Mode_Normal;//DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStruct.DMA_Priority = DMA_Priority_Medium;//DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	DMA_InitStruct.DMA_M2M = DMA_M2M_Enable;//DMA_InitStructure.DMA_M2M = DMA_M2M_Enable;
	DMA_Init(DMA1_Channel5, &DMA_InitStruct);

	DMA_Cmd(DMA1_Channel5, ENABLE);
	return Success;
}
Status SendBit_WS2812B(uint16_t value)
{
	TIM4->CCR3 = value;
	return Success;
}
