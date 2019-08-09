#include "stm32f10x_gpio.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_tim.h"
#include <stdint.h>
#include <string.h>

#define Element 627
#define Get_Bit(Color, bit) (Color &(1 << bit))

static uint16_t n;
volatile static uint32_t a[Element];
static uint32_t ClockOSCS;
static uint8_t ClockSystem;
static TIM_OCInitTypeDef TIM_OCStruct;
static TIM_TimeBaseInitTypeDef TIM_BaseStruct;
static DMA_InitTypeDef DMA_InitStruct;



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

typedef enum LED_type{
	LED1 = 1,
	LED2,
	LED3,
	LED4,
	LED5,
	LED6,
	LED7,
	LED8,
	LED9,
	LED10,
	LED11,
	LED12,
	LED13,
	LED14,
	LED15,
	LED16,
	LED17,
	LED18,
	LED19,
	LED20,
	LED21,
	LED22,
	LED23,
	LED24,
} LED;

Status Init_Led(void);
Status Init_Clock(void);
Status Init_GPIO(void);
Status Init_Clock(void);
Status Init_PWM(void);
Status Init_DMA(void);
Status SendBit_WS2812B(uint16_t value);
Status WriteLed(int Led, uint8_t Green, uint8_t Red, uint8_t Blue);
Status ClearALL_Led(void);
Status Show(uint32_t time);
Status EndShow(void);
void test(void);
void test2(void);

static void Delay(uint32_t a){
	while(a)
	{
		--a;
	}
}

