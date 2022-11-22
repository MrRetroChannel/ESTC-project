#pragma once
#include "nrf_delay.h"
#include "boards.h"
#include "user_button/sw1.h"

#define LED_Y NRF_GPIO_PIN_MAP(0, 6)
#define LED_R NRF_GPIO_PIN_MAP(0, 8)
#define LED_G NRF_GPIO_PIN_MAP(1, 9)
#define LED_B NRF_GPIO_PIN_MAP(0, 12)

#define DUTY_CYCLE 1000

void init_led(void);

int colorToLed(char color);

void turn_on(char color);

void turn_off(char color);

void blink(char color, size_t delay);

void led_set_brightness(char color, double percent);

void pwm_cycle(char color);