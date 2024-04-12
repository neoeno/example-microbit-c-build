#include "MicroBit.h"

MicroBit uBit;

#ifdef __cplusplus

extern "C" {

    void microbit_init() {
        uBit.init();
    }

    void microbit_panic(int statusCode) {
        uBit.panic(statusCode);
    }

    void display(char message[]) {
        uBit.display.scroll(message, 50);
    }

}

#endif
