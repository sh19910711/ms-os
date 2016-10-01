#include "baseos.h"
#include "GPIO.h"
#include "Timer.h"


void setup() {

    GPIO.set_pin_mode(4, 1);
    Timer.set_interval(1000, []() {
        if (GPIO.is_on(4))
            GPIO.write(4, 0);
        else
            GPIO.write(4, 1);
    });
}
