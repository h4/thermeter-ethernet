#include "led_display.h"

void init_pin(uint32_t pin, GPIO_TypeDef *port) {
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(port, &GPIO_InitStruct);
}

void LED_Init() {
  LED_GPIO_CLK_ENABLE();
  DISPLAY_GPIO_CLK_ENABLE();

  init_pin(GPIO_PIN_0, GPIOA);
  init_pin(GPIO_PIN_1, GPIOA);
  init_pin(GPIO_PIN_2, GPIOA);
  init_pin(GPIO_PIN_3, GPIOA);
  init_pin(GPIO_PIN_4, GPIOA);
  init_pin(GPIO_PIN_5, GPIOA);
  init_pin(GPIO_PIN_6, GPIOA);
  init_pin(GPIO_PIN_7, GPIOA);

  init_pin(GPIO_PIN_8, GPIOA);
  init_pin(GPIO_PIN_9, GPIOA);
  init_pin(GPIO_PIN_10, GPIOA);

  init_pin(GPIO_PIN_13, GPIOC);
}
