#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"

int main(void)
{
    bsp_board_init(BSP_INIT_LEDS);
    int id[] = {6, 5, 9, 9};
    while (true)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int i1 = 0; i1 < id[i]; i1++)
            {
                bsp_board_led_on(i);
                nrf_delay_ms(500);
                bsp_board_led_off(i);
                nrf_delay_ms(500);
            }
        }
    }
}
