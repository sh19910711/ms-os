#ifndef __LED_H__
#define __LED_H__

class LED {
    int pin;

public:
    LED() = default;
    LED(int gpio_pin);
    void on();
    void off();
};

#endif
