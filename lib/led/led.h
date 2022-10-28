#pragma once
#include "nrf_delay.h"
#include "boards.h"

int colorToLed(char color);

void blink(char color, size_t delay);

void blink_stay(char color, size_t delay);