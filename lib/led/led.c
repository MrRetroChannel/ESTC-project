#include "led.h"

void init_led(void)
{
    nrf_gpio_cfg_output(LED_Y);
    turn_off('Y');
    nrf_gpio_cfg_output(LED_R);
    turn_off('R');
    nrf_gpio_cfg_output(LED_G);
    turn_off('G');
    nrf_gpio_cfg_output(LED_B);
    turn_off('B');
}

int colorToLed(char color)
{
    switch (color)
    {
        case 'Y':
            return LED_Y;
        case 'R':
            return LED_R;
        case 'G':
            return LED_G;
        case 'B':
            return LED_B;
        
    }

    return 0;
}

void turn_on(char color)
{
    nrf_gpio_pin_write(colorToLed(color), 0);
}

void turn_off(char color)
{
    nrf_gpio_pin_write(colorToLed(color), 1);
}

void blink(char color, size_t delay)
{
    turn_on(color);
    nrf_delay_ms(delay / 2);
    turn_off(color);
    nrf_delay_ms(delay / 2);
}

void led_set_brightness(char color, double percent)
{
    int led_work = DUTY_CYCLE / 100.0 * percent;
    do
    {
        turn_on(color);
        nrf_delay_us(led_work);
        turn_off(color);
        nrf_delay_us(DUTY_CYCLE - led_work);
    } while (was_pressed);
}

void pwm_cycle(char color)
{
    for (double i = 0.0; i <= 100.0; i += 0.1)
        led_set_brightness(color, i);
    
    for (double i = 100.0; i >= 0.0; i -= 0.1)
        led_set_brightness(color, i);
}