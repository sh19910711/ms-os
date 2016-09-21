#include "baseos.h"
#include "GPIO.h"


void setup() {

    GPIO.set_pin_mode(4, 1);
    for (;;) {
       GPIO.write(4, 1);
       for (volatile int i=0; i < 0x10000; i++);
       GPIO.write(4, 0);
       for (volatile int i=0; i < 0x10000; i++);
    }
}
