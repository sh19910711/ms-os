#include "loop.h"

// XXX
#ifdef ARCH_ESP8266
#include "arch/esp8266/finfo.h"
#endif

void start_loop() {

    finfo->start_loop();
}
