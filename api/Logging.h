#ifndef __BASEOS_LOGGING_H__
#define __BASEOS_LOGGING_H__

#include <resea.h>

class _Logging {
public:
    void print(const char *s);
    void printf(const char *fmt, ...);
    void println(const char *s);
    void printlnf(const char *fmt, ...);

    void error(const char *s);
    void errorf(const char *fmt, ...);
    void errorln(const char *s);
    void errorlnf(const char *fmt, ...);
};

#endif
