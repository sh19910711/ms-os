#ifndef __LED_H__
#define __LED_H__

class LED {
    int pin;

public:
    LED() = default;
    LED(struct led_args *args);
    void on();
    void off();
};

#endif
