#include <app.h>

void setup() {

    Timer.set_interval(BLINK_INTERVAL, [](){
        if (MainLED.is_on())
           MainLED.off();
        else
           MainLED.on();
    });
}
