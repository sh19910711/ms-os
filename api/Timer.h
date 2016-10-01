#ifndef __TIMER_H__
#define __TIMER_H__

#include <resea.h>

class _Timer {
public:
    _Timer();
    void set_interval(int ms, void (*callback)());
};

#endif
