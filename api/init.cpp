#include <resea.h>
#include "baseos.h"

channel_t channel_server = 0;
class _GPIO GPIO;
void setup();

extern "C" void csapp_startup(void) {
    
    channel_server = connect_to_local(1);
    GPIO = _GPIO();
    setup();
}
