#include "baseos.h"
#include "GPIO.h"
#include "arch/esp8266/finfo.h"


void loop() {
    static int x = 0;
    
    if (x % 2) {
        GPIO.write(4, 0);
        for (volatile int i=0; i < 0x1000; i++);
    } else {
        GPIO.write(4, 1);
        for (volatile int i=0; i < 0x1000; i++);
    }

    int button = GPIO.read(5);
    if (button) {
        char buf[64];
        finfo->http_request("133.242.229.85", 3000, "POST", "/clap",
                            "", "", 0, &buf, sizeof(buf));
    }
    
    x++;
}

void setup() {

    GPIO.set_pin_mode(12, 1);
    GPIO.set_pin_mode(4, 1);
    GPIO.set_pin_mode(5, 0);
    GPIO.write(12, 1);
    finfo->set_loop(loop);
}
