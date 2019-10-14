#include "stm32f1xx_hal.h"

#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOC_CLK_ENABLE()
#define DISPLAY_GPIO_CLK_ENABLE()              __HAL_RCC_GPIOA_CLK_ENABLE()

void LED_Init();
