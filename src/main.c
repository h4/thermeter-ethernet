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

  int pos = 0;
  int tick = 0;

  while (1)
  {
    LED_Num(pos);
    if (tick > 2000) {
      tick = 0;
      pos++;
      if (pos > 999) {
        pos = 0;
      }
    }
    tick++;
  }
}

void SysTick_Handler(void) {
  HAL_IncTick();
}
