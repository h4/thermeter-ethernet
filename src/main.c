#include "main.h"
#include "led_display.h"

void LED_Init();

int main(void) {
  HAL_Init();
  LED_Init();

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
