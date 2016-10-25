#ifndef __ENV_H__
#define __ENV_H__

#include <resea.h>

#define ENV_BUFFER_SIZE 512
#define ENV_SEP ((char) 0x04)

class _ENV {
public:
    _ENV();
    bool get(const char *name, int *value);
    bool get(const char *name, char *value, size_t value_size);

private:
    string vars;;
};

#endif
