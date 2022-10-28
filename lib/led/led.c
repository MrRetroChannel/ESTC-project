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

void blink(char color, size_t delay)
{
    bsp_board_led_on(colorToLed(color));
    nrf_delay_ms(delay);
    bsp_board_led_off(colorToLed(color));
    nrf_delay_ms(delay);
}

void blink_stay(char color, size_t delay)
{
    static char c = 0;
    static bool sleep = false;

    bsp_board_led_off(colorToLed(c));
    
    c = color;

    if (sleep)
        nrf_delay_ms(delay);

    int prev = nrf_gpio_pin_read(BUTTON);
    bsp_board_led_on(colorToLed(color));
    nrf_delay_ms(delay);

    if (nrf_gpio_pin_read(BUTTON) == prev)
    {
        bsp_board_led_off(colorToLed(color));
        nrf_delay_ms(delay);
        sleep = false;
    }
    else
        sleep = true;
}