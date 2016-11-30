#ifndef __GPIO_H__
#define __GPIO_H__

#include <resea.h>
#include <resea/gpio.h>

// GPIO_OUTPUT_PIN, GPIO_INPUT_PIN, GPIO_HIGH, GPIO_LOW
// are defined in resea/gpio.h

class _GPIO {
    channel_t gpio_server, interrupt_server;
  public:
    _GPIO();
    void set_pin_mode(int pin, int mode);
    void write(int pin, int value);
    int read(int pin);
    int read_analog(int pin);
    bool is_on(int pin);
    void toggle(int pin);
    void on_change(int pin, void (*callback)());
};

#endif
