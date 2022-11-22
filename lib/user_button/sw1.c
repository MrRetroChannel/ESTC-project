#include "sw1.h"

APP_TIMER_DEF(buttonDebounceTimer);

APP_TIMER_DEF(clicksCounterTimer);

volatile bool was_pressed = false, debouncing = false;

volatile uint16_t clicks_counter = 0;

void init_button()
{
    app_timer_create(&buttonDebounceTimer, APP_TIMER_MODE_SINGLE_SHOT, debounce_callback);
    app_timer_create(&clicksCounterTimer , APP_TIMER_MODE_REPEATED, counter_reset       );
    app_timer_start (clicksCounterTimer  , APP_TIMER_TICKS(DOUBLE_CLICK_DELAY)   , NULL                );

    nrfx_gpiote_init();
    nrfx_gpiote_in_config_t button_cfg = NRFX_GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);

    nrfx_gpiote_in_init(BUTTON, &button_cfg, button_pressed_event);
    nrfx_gpiote_in_event_enable(BUTTON, true);
}

bool button_is_pressed()
{
    return !nrf_gpio_pin_read(BUTTON);
}

void button_pressed_event()
{
    if (!debouncing)
    {
        app_timer_start(buttonDebounceTimer, APP_TIMER_TICKS(DEBOUNCE_DELAY), NULL);
        debouncing = true;
    }
}

void debounce_callback(void* p_context)
{
    if (button_is_pressed())
        clicks_counter++;

    if (clicks_counter == 2)
        was_pressed = !was_pressed, clicks_counter = 0;

    debouncing = false;
}

void counter_reset(void* p_context)
{
    NRF_LOG_INFO("clicks_counter = %i", clicks_counter);
    LOG_BACKEND_USB_PROCESS();
    clicks_counter = 0;
}