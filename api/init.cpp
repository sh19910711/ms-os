#include <resea.h>
#include "app.h"
#include "loop.h"

channel_t channel_server = 0;
class _GPIO GPIO;
class _Timer Timer;

extern "C" void csapp_startup(void) {

    channel_server = connect_to_local(1);
    GPIO  = _GPIO();
    Timer = _Timer();

    setup();
    start_loop();
}
