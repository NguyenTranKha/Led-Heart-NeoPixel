#include "NeoPixel.h"

#define NEO_KHZ800 0x0000

#define NEO_RGB  ((0<<6) | (0<<4) | (1<<2) | (2)) ///< Transmit as R,G,B
#define NEO_RBG  ((0<<6) | (0<<4) | (2<<2) | (1)) ///< Transmit as R,B,G
#define NEO_GRB  ((1<<6) | (1<<4) | (0<<2) | (2)) ///< Transmit as G,R,B
#define NEO_GBR  ((2<<6) | (2<<4) | (0<<2) | (1)) ///< Transmit as G,B,R
#define NEO_BRG  ((1<<6) | (1<<4) | (2<<2) | (0)) ///< Transmit as B,R,G
#define NEO_BGR  ((2<<6) | (2<<4) | (1<<2) | (0)) ///< Transmit as B,G,R

// RGBW NeoPixel permutations; all 4 offsets are distinct
// Offset:         W          R          G          B
#define NEO_WRGB ((0<<6) | (1<<4) | (2<<2) | (3)) ///< Transmit as W,R,G,B
#define NEO_WRBG ((0<<6) | (1<<4) | (3<<2) | (2)) ///< Transmit as W,R,B,G
#define NEO_WGRB ((0<<6) | (2<<4) | (1<<2) | (3)) ///< Transmit as W,G,R,B
#define NEO_WGBR ((0<<6) | (3<<4) | (1<<2) | (2)) ///< Transmit as W,G,B,R
#define NEO_WBRG ((0<<6) | (2<<4) | (3<<2) | (1)) ///< Transmit as W,B,R,G
#define NEO_WBGR ((0<<6) | (3<<4) | (2<<2) | (1)) ///< Transmit as W,B,G,R

#define NEO_RWGB ((1<<6) | (0<<4) | (2<<2) | (3)) ///< Transmit as R,W,G,B
#define NEO_RWBG ((1<<6) | (0<<4) | (3<<2) | (2)) ///< Transmit as R,W,B,G
#define NEO_RGWB ((2<<6) | (0<<4) | (1<<2) | (3)) ///< Transmit as R,G,W,B
#define NEO_RGBW ((3<<6) | (0<<4) | (1<<2) | (2)) ///< Transmit as R,G,B,W
#define NEO_RBWG ((2<<6) | (0<<4) | (3<<2) | (1)) ///< Transmit as R,B,W,G
#define NEO_RBGW ((3<<6) | (0<<4) | (2<<2) | (1)) ///< Transmit as R,B,G,W

#define NEO_GWRB ((1<<6) | (2<<4) | (0<<2) | (3)) ///< Transmit as G,W,R,B
#define NEO_GWBR ((1<<6) | (3<<4) | (0<<2) | (2)) ///< Transmit as G,W,B,R
#define NEO_GRWB ((2<<6) | (1<<4) | (0<<2) | (3)) ///< Transmit as G,R,W,B
#define NEO_GRBW ((3<<6) | (1<<4) | (0<<2) | (2)) ///< Transmit as G,R,B,W
#define NEO_GBWR ((2<<6) | (3<<4) | (0<<2) | (1)) ///< Transmit as G,B,W,R
#define NEO_GBRW ((3<<6) | (2<<4) | (0<<2) | (1)) ///< Transmit as G,B,R,W

#define NEO_BWRG ((1<<6) | (2<<4) | (3<<2) | (0)) ///< Transmit as B,W,R,G
#define NEO_BWGR ((1<<6) | (3<<4) | (2<<2) | (0)) ///< Transmit as B,W,G,R
#define NEO_BRWG ((2<<6) | (1<<4) | (3<<2) | (0)) ///< Transmit as B,R,W,G
#define NEO_BRGW ((3<<6) | (1<<4) | (2<<2) | (0)) ///< Transmit as B,R,G,W
#define NEO_BGWR ((2<<6) | (3<<4) | (1<<2) | (0)) ///< Transmit as B,G,W,R
#define NEO_BGRW ((3<<6) | (2<<4) | (1<<2) | (0)) ///< Transmit as B,G,R,W

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
  TIM_BaseStruct.TIM_Period = 19; /* 800Hz PWM */
  TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_BaseStruct.TIM_RepetitionCounter = 0;
  TIM_TimeBaseInit(TIM4, &TIM_BaseStruct);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
  
	
	TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_Low;
	
	TIM_Cmd(TIM4, ENABLE);
	
	return Success;
}

Status SendBit_WS2812B(uint16_t value)
{
	TIM_OCStruct.TIM_Pulse = value;
	TIM_OC3Init(TIM4, &TIM_OCStruct);
	return Success;
}
