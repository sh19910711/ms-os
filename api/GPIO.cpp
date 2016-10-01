#include <resea.h>
#include <resea/channel.h>
#include <resea/gpio.h>
#include "baseos.h"
#include "GPIO.h"


_GPIO::_GPIO() {

    gpio_server = open();
    // TODO: check retrun values

    result_t r;
    call_channel_connect(channel_server, gpio_server, GPIO_INTERFACE, &r);
}


void _GPIO::set_pin_mode(int pin, int mode) {
    result_t r;
    call_gpio_set_pin_mode(gpio_server, pin, mode, &r);
}


int _GPIO::read(int pin) {
    result_t r;
    int value;
    call_gpio_read(gpio_server, pin, &r, &value);
    return value;
}


void _GPIO::write(int pin, int value) {
    result_t r;
    call_gpio_write(gpio_server, pin, value, &r);
}


bool _GPIO::is_on(int pin) {

    return _GPIO::read(pin) != 0;
}
