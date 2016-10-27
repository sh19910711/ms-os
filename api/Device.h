#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <resea.h>

class _Device {
public:
    const char *get_device_secret();
    const char *get_server_url();
    NORETURN void update(unsigned long deployment_id);
    NORETURN void reset();
    NORETURN void reset(const char *errmsg);
};

#endif
