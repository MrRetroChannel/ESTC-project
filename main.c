#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "led/led.h"
#include "user_button/sw1.h"
#include "timers/timers.h"
#include "logs/logs.h"

#define ID_SIZE 4

const int id[ID_SIZE] = {6, 5, 9, 9};

int id_seq_size = id[0] + id[1] + id[2] + id[3];

const char* id_seq = "YYYYYYRRRRRGGGGGGGGGBBBBBBBBB";

int main(void)
{
    init_timers();
    init_button();
    init_led();
    
    int cur_color = 0;

    while (1)
    {
        pwm_cycle(id_seq[cur_color++]);
        cur_color = cur_color == id_seq_size? 0 : cur_color;
    }
}
