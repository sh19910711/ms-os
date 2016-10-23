#include <app.h>


void _Logging::print(const char *s) {

    printfmt("%s", s);
}


void _Logging::printf(const char *fmt, ...) {
    va_list vargs;

    va_start(vargs, fmt);
    vprintfmt(fmt, vargs);
    va_end(vargs);
}


void _Logging::println(const char *s) {

    printfmt("%s\n", s);
}


void _Logging::printlnf(const char *fmt, ...) {
    va_list vargs;

    va_start(vargs, fmt);
    vprintfmt(fmt, vargs);
    va_end(vargs);

    printfmt("\n");
}


void _Logging::error(const char *s) {

    printfmt("!%s", s);
}


void _Logging::errorf(const char *fmt, ...) {
    va_list vargs;

    printfmt("!");

    va_start(vargs, fmt);
    vprintfmt(fmt, vargs);
    va_end(vargs);

    printfmt("\n");
}


void _Logging::errorln(const char *s) {

    printfmt("!%s\n", s);
}


void _Logging::errorlnf(const char *fmt, ...) {
    va_list vargs;

    printfmt("!");

    va_start(vargs, fmt);
    vprintfmt(fmt, vargs);
    va_end(vargs);

    printfmt("\n");
}
