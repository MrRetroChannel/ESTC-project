#pragma once
#include "nrf_delay.h"
#include "boards.h"
#include "nrfx_gpiote.h"
#include "timers/timers.h"
#include "logs/logs.h"

#define BUTTON NRF_GPIO_PIN_MAP(1, 6)

#define DEBOUNCE_DELAY 50

#define DOUBLE_CLICK_DELAY 500

extern volatile bool was_pressed, debouncing;

extern volatile uint16_t clicks_counter;

void init_button(void);

bool button_is_pressed(void);

void button_pressed_event(void);

void debounce_callback(void* p_context);

void counter_reset(void* p_context);