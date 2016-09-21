#ifndef __GPIO_H__
#define __GPIO_H__

#include <resea.h>

class _GPIO {
    channel_t gpio_server;
  public:
    _GPIO();
    void set_pin_mode(int pin, int mode);
    void write(int pin, int value);
    int read(int pin);
};

#endif
