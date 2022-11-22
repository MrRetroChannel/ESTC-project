#pragma once
#include "app_timer.h"
#include "drv_rtc.h"
#include "nrf_drv_clock.h"

#define TIMER_CHECK(function) APP_ERROR_CHECK(function)

void init_timers(void);