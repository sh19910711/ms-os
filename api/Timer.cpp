#include <resea.h>
#include "baseos.h"
#include "Timer.h"

#include "arch/esp8266/finfo.h" // TODO


_Timer::_Timer() {
}


void _Timer::set_interval(int ms, void (*callback)()) {

    finfo->set_interval(ms, callback);
}

