#pragma once
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_log_backend_usb.h"

#define LOG(msg) do {NRF_LOG_INFO(msg); LOG_BACKEND_USB_PROCESS();} while (false)

void init_logs(void);