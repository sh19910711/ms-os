#include <app.h>


_ENV::_ENV() {
    vars.reserve(ENV_BUFFER_SIZE);

    // TODO: use memset
    char *p = vars.buffer();
    for (size_t i = 0; i < vars.capacity(); i++, p++)
        *p = 0;

    string url;
    url += Device.get_server_url();
    url += "/api/devices/";
    url += Device.get_device_secret();
    url += "/envvars";

    if (HTTP.GET(url, "", vars.buffer(), vars.capacity()) != 200) {
        Logging.errorln("failed to download envvars");
    }

    vars._length = strlen(vars.buffer()); // FIXME
}


bool _ENV::get(const char *name, char *value, size_t value_size) {

    size_t name_len = strlen(name);
    while (1) {
        Logging.printlnf("envs: '%s'", vars.c_str());
        size_t offset = vars.find(name);
        if (offset < 0)
            return false; // not found

        size_t prev = offset - 1;
        size_t eq = offset + name_len;
        if ((offset == 0 || vars.at(prev) == ENV_SEP) && vars.at(eq) == '=') {
            // found
            const char *copy_from = vars.c_str() + eq + 1;
            int sep = vars.find(ENV_SEP, offset);
            size_t end = (sep > 0) ? sep : vars.length();
            size_t copy_size = end - eq - 1;

            if (value_size <= copy_size + 1) {
                Logging.errorln("envvar is too long; expand `value_size`");
                return false;
            }

            memcpy_s(value, value_size, copy_from, copy_size);
            value[copy_size] = '\0';
            return true;
        } else {
            offset = vars.find(ENV_SEP) + 1;
        }
    }
}


bool _ENV::get(const char *name, int *value) {

    /* TODO */
    return false;
}
