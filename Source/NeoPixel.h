#include "stm32f10x_gpio.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_tim.h"
#include <stdint.h>

static uint32_t ClockOSCS;
static uint8_t ClockSystem;
static TIM_OCInitTypeDef TIM_OCStruct;
static TIM_TimeBaseInitTypeDef TIM_BaseStruct;



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
Status SendBit_WS2812B(uint16_t value);

static void Delay(void){
	uint32_t a = 30000000;
	while(a)
	{
		--a;
	}
	//SendBit_WS2812B(0);
}

