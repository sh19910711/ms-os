#include <resea/channel.h>
#include <resea/i2c.h>
#include <app.h>


_I2C::_I2C() {

    i2c_server = open();
    // TODO: check return values

    result_t r;
    call_channel_connect(channel_server, i2c_server, I2C_INTERFACE, &r);
}


void _I2C::send(int addr, const void *payload, size_t size) {
    result_t r;

    call_i2c_send(i2c_server, addr, (void *) payload, size, &r);
    // TODO: check return values
}


void _I2C::receive(int addr, void *payload, size_t size) {
    result_t r;

    call_i2c_send(i2c_server, addr, payload, size, &r);
    // TODO: check return values
}
