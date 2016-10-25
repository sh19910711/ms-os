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


const char *_Device::get_device_secret() {

// XXX
#ifdef ARCH_ESP8266
    return finfo->get_device_secret();
#endif
}


const char *_Device::get_server_url() {

// XXX
#ifdef ARCH_ESP8266
    return finfo->get_server_url();
#endif
}


NORETURN void _Device::reset(const char *errmsg) {

    Logging.errorln(errmsg);
    reset();
}
