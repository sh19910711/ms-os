#include <resea.h>
#include <resea/channel.h>
#include <resea/makestack.h>
#include <app.h>


_Device::_Device() {

    // Note that `makestack_server` is one of a *Resea* server program,
    // not MakeStack Server.
    makestack_server = open();

    // TODO: check return values

    result_t r;
    call_channel_connect(channel_server, makestack_server, MAKESTACK_INTERFACE, &r);
}

NORETURN void _Device::reset() {
    call_makestack_reset(makestack_server);
    for(;;);
}


NORETURN void _Device::reset(const char *errmsg) {

    Logging.errorln(errmsg);
    reset();
}


static char *device_secret = nullptr;
const char *_Device::get_device_secret() {

    if (!device_secret) {
        size_t len;
        call_makestack_get_device_secret(makestack_server, (void **) &device_secret, &len);
    }

    return device_secret;
}


static char *server_url = nullptr;
const char *_Device::get_server_url() {

    if (!server_url) {
        size_t len;
        call_makestack_get_server_url(makestack_server, (void **) &server_url, &len);
    }

    return server_url;
}


unsigned long _Device::get_deployment_id() {

    int deployment_id;
    call_makestack_get_deployment_id(makestack_server, &deployment_id);
    return deployment_id;
}


NORETURN void _Device::update(unsigned long deployment_id) {


    call_makestack_update(makestack_server, deployment_id);
    for(;;);
}
