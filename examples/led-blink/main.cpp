#include "baseos.h"
#include "GPIO.h"
#include "arch/esp8266/finfo.h"


void loop() {
    GPIO.write(4, 1);
    for (volatile int i=0; i < 0x1000; i++);
    GPIO.write(4, 0);
    for (volatile int i=0; i < 0x500; i++);
}

void setup() {

    GPIO.set_pin_mode(12, 1);
    GPIO.set_pin_mode(4, 1);
    GPIO.write(12, 1);
    finfo->set_loop(loop);
}
