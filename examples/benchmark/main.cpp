#include <app.h>

LED BlinkLED, IntrLED;

void setup() {
    BlinkLED = LED(BLINK_LED_PIN);
    IntrLED  = LED(INTR_LED_PIN);

    Timer.set_interval(BLINK_INTERVAL, []() {
        BlinkLED.toggle();
    });

    GPIO.on_change(BUTTON_PIN, []() {
        IntrLED.toggle();
    });
}
