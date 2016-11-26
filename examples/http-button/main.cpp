#include <app.h>

static char device_name[32];
static int state = 0;
void setup() {
    ENV.get("device_name", (char *) &device_name, sizeof(device_name));
    GPIO.set_pin_mode(BUTTON_GPIO_PIN, GPIO_INPUT_PIN);

    Timer.set_interval(POLLING_INTERVAL, []() {
        int new_state = GPIO.read(BUTTON_GPIO_PIN);
        if (new_state != state) {
/*
            string url;
            url.from_fmt("%s%s?button=%s", HTTP_BUTTON_SERVER_URL,
                         (state) ? "push" : "pop", "?button=", device_name);
            HTTP.POST(url);
*/
            char resp[8];
            string url;
            url += HTTP_BUTTON_SERVER_URL;
            url += (new_state) ? "push" : "pop";
            url += "?button=";
            url += device_name;
            HTTP.POST(url, "", 0, "", &resp, sizeof(resp));
            state = new_state;
        }
    });
}
