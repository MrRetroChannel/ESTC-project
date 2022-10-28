#pragma once
#include "nrf_delay.h"
#include "boards.h"

#define BUTTON NRF_GPIO_PIN_MAP(1, 6)

bool button_pressed();