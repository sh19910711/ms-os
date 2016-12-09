#include <resea.h>
#include <resea/interrupt.h>
#include <resea/timer.h>
#include <string.h>
#include "app.h"
#include "heartbeat.h"


channel_t app_channel;
channel_t channel_server;
class _GPIO GPIO;
class _Timer Timer;
class _Logging Logging;
class _HTTP HTTP;
class _ENV ENV;
class _Device Device;


static void mainloop() {
    payload_t buf[4];
    channel_t reply_to;

    if(recv(app_channel, (void *) &buf, sizeof(buf), 0, &reply_to) != OK) {
        return;
    }

    if (TIMER_TIMEOUT == buf[1] ||
        (INTERRUPT_INTERRUPT0 <= buf[1] && buf[1] <= INTERRUPT_INTERRUPT15)) {
        void (*callback)() = (void (*)()) buf[2];
        callback();
    }
}


extern "C" void app_startup(void) {

    app_channel = open();

    channel_server = connect_to_local(1);
    Logging = _Logging();
    Device  = _Device();
    GPIO    = _GPIO();
    Timer   = _Timer();
    HTTP    = _HTTP();
    ENV     = _ENV();

    set_deployment_id();

    Timer.set_interval(5000, []() {
        send_heartbeat();
    });

    DEBUG("running setup()");
    setup();
    DEBUG("entering mainloop");

    for (;;) {
        mainloop();
    }
}
