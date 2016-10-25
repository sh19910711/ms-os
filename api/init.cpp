#include <resea.h>
#include "app.h"
#include "loop.h"

channel_t channel_server = 0;
class _GPIO GPIO;
class _Timer Timer;
class _Logging Logging;
class _HTTP HTTP;
class _Device Device;

extern "C" void csapp_startup(void) {

    channel_server = connect_to_local(1);
    Logging = _Logging();
    Device = _Device();
    GPIO  = _GPIO();
    Timer = _Timer();
    HTTP = _HTTP();

    init_drivers();
    setup();
    start_loop();
}
