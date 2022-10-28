#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "led/led.h"
#include "user_button/sw1.h"

int main(void)
{
    bsp_board_init(BSP_INIT_LEDS);
    //int id[] = {6, 5, 9, 9};

    const char* led = "RRGGGB";

    //char colors[] = {'Y', 'R', 'G', 'B'};

    nrf_gpio_cfg_input(BUTTON, NRF_GPIO_PIN_PULLUP);
    
    int i = 0;
    while (true)
    {
        while (button_pressed())
        {
            blink_stay(led[i++], 1000);
            i = i == strlen(led) ? 0 : i;
        }
    }
}