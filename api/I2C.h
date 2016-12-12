#ifndef __I2C_H__
#define __I2C_H__

#include <resea.h>

class _I2C {
    channel_t i2c_server;
  public:
    _I2C();
    void send(int addr, const void *payload, size_t size);
    void receive(int addr, void *payload, size_t size);
};

#endif
