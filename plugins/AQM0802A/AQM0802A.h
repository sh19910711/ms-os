#ifndef __AQM0802A_H__
#define __AQM0802A_H__

enum {
    AQM0802A_CMD  = 0x00,
    AQM0802A_DATA = 0x40
};

class AQM0802A {
    int addr, pos;
    void send(int type, uint8_t data);

public:
    AQM0802A();
    void putchar(char ch);
    void print(const char *s);
    void clear();
};

#endif
