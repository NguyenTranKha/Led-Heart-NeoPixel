#include "stm32f10x_gpio.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_tim.h"
#include <stdint.h>

#define ADDRESS_DMAR /*TIM4->DMAR*/ 0x4000083C

static uint16_t a[24];
static uint32_t *b = a;
static uint32_t ClockOSCS;
static uint8_t ClockSystem;
static TIM_OCInitTypeDef TIM_OCStruct;
static TIM_TimeBaseInitTypeDef TIM_BaseStruct;
static DMA_InitTypeDef DMA_InitStruct;
static NVIC_InitTypeDef NVIC_InitStructure;



uint32_t GetClockOSC(void);

typedef struct WS2812_Type{
	uint8_t Red;
	uint8_t Green;
	uint8_t Blue;
}ws2812b;

typedef enum Status_type{
	Fail = 0,
	Success = 1
} Status;

Status Init_Clock(void);
Status Init_GPIO(void);
Status Init_Clock(void);
Status Init_PWM(void);
Status Init_DMA(void);
Status SendBit_WS2812B(uint16_t value);

static void Delay(uint32_t a){
	while(a)
	{
		--a;
	}
}

