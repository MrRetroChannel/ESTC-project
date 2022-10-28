#include "led.h"
#include "user_button/sw1.h"

int colorToLed(char color)
{
    switch (color)
    {
        case 'R':
            return 1;
        case 'G':
            return 2;
        case 'B':
            return 3;
    }

    return 0;
}

void turnOn(char color)
{
    bsp_board_led_on(colorToLed(color));
}

void turnOff(char color)
{
    bsp_board_led_off(colorToLed(color));
}

void blink(char color, size_t delay)
{
    turnOn(color);
    nrf_delay_ms(delay);
    turnOff(color);
    nrf_delay_ms(delay);
}

bool blink_stay(char color, size_t delay)
{
    static char c = 0;
    static bool sleep = false;

    turnOff(c);
    
    c = color;

    if (sleep)
        nrf_delay_ms(delay);

    if (button_pressed())
    {
        turnOn(color);
        nrf_delay_ms(delay);

        if (button_pressed())
        {
            turnOff(color);
            nrf_delay_ms(delay);
            sleep = false;
        }
        else
            sleep = true;

        return true;
    }

    return false;
}