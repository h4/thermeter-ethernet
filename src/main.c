#include "main.h"
#include "led_display.h"

void LED_Init();

int main(void) {
  HAL_Init();
  LED_Init();

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);

  while (1)
  {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(500);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(500);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(500);
  }
}

void SysTick_Handler(void) {
  HAL_IncTick();
}
