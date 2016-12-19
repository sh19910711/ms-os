#include <app.h>

AQM0802A::AQM0802A() {
    // TODO: support more LCDs
    addr = 0x3e;
    pos = 0;

    send(AQM0802A_CMD, 0x39);
    send(AQM0802A_CMD, 0x14);
    send(AQM0802A_CMD, 0x74);
    send(AQM0802A_CMD, 0x56);
    send(AQM0802A_CMD, 0x6c);
    send(AQM0802A_CMD, 0x0c);

    clear();
}


void AQM0802A::send(int type, uint8_t data) {
    uint8_t buf[2];

    buf[0] = type;
    buf[1] = data;
    I2C.send(addr, &buf, sizeof(buf));
}


void AQM0802A::putchar(char ch) {
    if (ch < 0x20 || ch > 0x7f) {
        // Nonprintable characters.
        ch = ' ';
    }

    if (pos == 0x08) {
        pos = 0x40;
    } else if (pos == 0x48) {
        clear();
    }

    send(AQM0802A_CMD, 0x80 + pos);
    send(AQM0802A_DATA, ch);
    pos++;
}


void AQM0802A::print(const char *s) {
    clear();

    size_t n = 16;
    while (*s && n > 0) {
        putchar(*s);
        s++;
        n--;
    }
}


void AQM0802A::clear() {

    send(AQM0802A_CMD, 0x01);
    pos = 0;
}
