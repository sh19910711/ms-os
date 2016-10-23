#include <app.h>


// XXX
#ifdef ARCH_ESP8266
#include "arch/esp8266/finfo.h"
#endif


NORETURN void _Device::reset() {

// XXX
#ifdef ARCH_ESP8266
    finfo->update(-1);
#endif
}


NORETURN void _Device::reset(const char *errmsg) {

    Logging.errorln(errmsg);
    reset();
}
