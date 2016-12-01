#ifndef __TIMER_H__
#define __TIMER_H__

#include <resea.h>

class _Timer {
    channel_t timer_server;
public:
    _Timer();
    void set_interval(int ms, void (*callback)());
    void set_oneshot(int ms, void (*callback)());
};

#endif
