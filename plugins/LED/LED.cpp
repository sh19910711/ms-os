#include <app.h>

LED::LED(int gpio_pin) {
    pin = gpio_pin;
    GPIO.set_pin_mode(pin, GPIO_OUTPUT_PIN);
}

void LED::on() {
    GPIO.write(pin, GPIO_HIGH);
}

void LED::off() {
    GPIO.write(pin, GPIO_LOW);
}
