#include "MicroBit.h"

MicroBit uBit;

#ifdef __cplusplus

extern "C" {

    #define BUTTON_A 1
    #define BUTTON_B 2

    void microbit_init() {
        uBit.init();
    }

    void microbit_panic(int statusCode) {
        uBit.panic(statusCode);
    }

    void scroll_display(char message[]) {
        uBit.display.scroll(message, 50);
    }

    void display_image(char image[]) {
        MicroBitImage imageObj(image);
        uBit.display.print(imageObj);
    }

    void sleep(int milliseconds) {
        uBit.sleep(milliseconds);
    }

    char read_serial_char() {
        return uBit.serial.read();
    }

    void on_button_pressed(int button, void (*callback)(MicroBitEvent)) {
        if (button == BUTTON_A) {
            uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, callback);
        } else if (button == BUTTON_B) {
            uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, callback);
        }
    }
}

#endif
