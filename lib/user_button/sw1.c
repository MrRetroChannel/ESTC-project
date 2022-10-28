#include "sw1.h"

bool button_pressed()
{
    return !nrf_gpio_pin_read(BUTTON);
}