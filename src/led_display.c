#include "led_display.h"

unsigned char NUM_MAP[10] = {
    //abcdefg.
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111
};

uint32_t PINS[8] = {
    GPIO_PIN_0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7
};

void init_pin(uint32_t pin, GPIO_TypeDef *port) {
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(port, &GPIO_InitStruct);
}

void LED_Init() {
  LED_GPIO_CLK_ENABLE();
  DISPLAY_GPIO_CLK_ENABLE();

  uint32_t PINS = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | 
    GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;

  init_pin(PINS, GPIOA);

  init_pin(GPIO_PIN_13, GPIOC);
}

void _show_digit(int num) {
  char bits = NUM_MAP[num];
  int curr_bit = 0;

  while (curr_bit < 8) {
    uint32_t pin = PINS[curr_bit];
    int val = (bits & (1 << curr_bit));

    HAL_GPIO_WritePin(GPIOA, pin, val);

    curr_bit++;
  }
}

void LED_Num(int num) {
  int n1 = num / 100;
  int n2 = (num % 100) / 10;
  int n3 = num % 10;

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10, 0);
  _show_digit(n1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
  
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10, 0);
  _show_digit(n2);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
  
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10, 0);
  _show_digit(n3);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
}
