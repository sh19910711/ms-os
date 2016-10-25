#include <app.h>


_ENV::_ENV() {
    vars.reserve(ENV_BUFFER_SIZE);

    string url;
    url += Device.get_server_url();
    url += "/api/devices/";
    url += Device.get_device_secret();

    if (HTTP.GET(url, "", vars.buffer(), vars.capacity()) != 200) {
        Logging.errorln("failed to download envvars");
    }
}


bool _ENV::get(const char *name, char *value, size_t value_size) {

    size_t name_len = strlen(name);
    while (1) {
        size_t offset = vars.find(name);
        if (offset < 0)
            return false; // not found

        size_t prev = offset - 1;
        size_t eq = offset + name_len;
        if ((offset == 0 || vars.at(prev) == ENV_SEP) && vars.at(eq) == '=') {
            // found
            const char *copy_from = vars.c_str() + eq + 1;
            size_t sep = vars.find(ENV_SEP, offset);
            size_t end = (sep > 0) ? sep : vars.length();
            size_t copy_size = end - offset - 1;

            if (value_size >= copy_size) {
                Logging.errorln("envvar is too long; expand `value_size`");
                return false;
            }

            size_t n = memcpy_s(value, value_size, copy_from, copy_size);
            value[n] = '\0';
            return true;
        }
    }
}


bool _ENV::get(const char *name, int *value) {

    /* TODO */
    return false;
}
