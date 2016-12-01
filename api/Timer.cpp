#include <resea/channel.h>
#include <resea/timer.h>
#include <app.h>
#include "Timer.h"


_Timer::_Timer() {
    timer_server = open();
    // TODO: check return values

    result_t r;
    call_channel_connect(channel_server, timer_server, TIMER_INTERFACE, &r);
}


void _Timer::set_interval(int ms, void (*callback)()) {

    result_t r;
    call_timer_set_interval(timer_server, app_channel, ms, (uintmax_t) callback, &r);
}


void _Timer::set_oneshot(int ms, void (*callback)()) {

    result_t r;
    call_timer_set_oneshot(timer_server, app_channel, ms, (uintmax_t) callback, &r);
}
