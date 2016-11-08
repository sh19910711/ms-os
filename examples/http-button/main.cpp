#include <app.h>


void post(int state) {
    char resp[128];
    string payload;
    payload += "{";
    payload += "\"id\": \"1\",";
    payload += "\"status\": \"";
    payload += (state)? "ON!" : "OFF!";
    payload += "\"}";

    string headers;
    headers += "Content-Type: application/json\r\n";

    HTTP.POST(CONFIG_SERVER_URL,
              payload.c_str(), payload.length(), headers, &resp, 512);
}


void setup() {
    static int state = GPIO_LOW;

    GPIO.set_pin_mode(CONFIG_BUTTON_GPIO_PIN, GPIO_INPUT_PIN);
    post(0);

    Timer.set_interval(CONFIG_POLLING_INTERVAL, []() {
        int new_state = GPIO.read(CONFIG_BUTTON_GPIO_PIN);
        if (new_state != state) {
            post(new_state);
            state = new_state;
        }
    });
}
