#include <malloc.h>
#include <app.h>
#include "heartbeat.h"


static unsigned long deployment_id = 0;

void send_heartbeat() {
    string url;
    url += Device.get_server_url();
    url += "/api/devices/";
    url += Device.get_device_secret();
    url += "/heartbeat?status=running";

    char *resp;
    size_t resp_size;
    int status;
    char *buffer;
    size_t buffer_size;

    buffer_size = get_buffered_log(&buffer);
    status = HTTP.PUT(url, buffer, buffer_size, "", (void **) &resp, &resp_size);

    if (status != 200) {
        free(buffer);
        Logging.errorlnf("heartbeat error: server returned %d", status);
        return;
    }

    if (resp[0] == 'X') {
        free(buffer);
        Logging.errorlnf("heartbeat error: no deployment");
        return;
    }

    unsigned long new_deployment_id = atol((const char *) &resp);
    if (new_deployment_id > deployment_id) {
        Logging.printlnf("new deployment detected, updating.... (%d -> %d)",
                         deployment_id, new_deployment_id);
        Device.update(new_deployment_id);
    }
}


void set_deployment_id() {

    if (deployment_id == 0)
        deployment_id = Device.get_deployment_id();
}
