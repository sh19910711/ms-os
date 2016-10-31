#include <app.h>


void setup() {
    static int state = 0;

    GPIO.set_pin_mode(CONFIG_BUTTON_GPIO_PIN, GPIO_INPUT_PIN);

    Timer.set_interval(CONFIG_POLLING_INTERVAL, []() {
        int new_state = GPIO.read(CONFIG_BUTTON_GPIO_PIN);
        if (new_state != state) {
            auto resp = new char[512];
            string payload;
            payload += "payload={\"text\": \"";
            payload += (new_state)? "ON!" : "OFF!";
            payload += "\"}",
            HTTP.POST(CONFIG_SLACK_URL,
                      payload.c_str(), payload.length(), "", &resp, 512);

            state = new_state;
        }
    });
}
