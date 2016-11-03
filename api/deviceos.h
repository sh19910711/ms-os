#ifndef __DEVICEOS_H__
#define __DEVICEOS_H__

#include <resea.h>
#include <string.h>
#include <string>

#include "GPIO.h"
#include "Timer.h"
#include "Device.h"
#include "Logging.h"
#include "HTTP.h"
#include "ENV.h"

// interfaces
#define DRIVER_GPIO  1

extern channel_t channel_server;
extern class _GPIO GPIO;
extern class _Timer Timer;
extern class _Device Device;
extern class _Logging Logging;
extern class _HTTP HTTP;

#endif
