#include "timers.h"

void init_timers(void)
{
    TIMER_CHECK(nrf_drv_clock_init());
    nrf_drv_clock_lfclk_request(NULL);
    TIMER_CHECK(app_timer_init());
}