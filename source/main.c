#include "bridge.h"

int main()
{
    microbit_init();

    run_button_app();

    while (1) {
        sleep(100);
    }

    microbit_panic( 123 );
}

void greet(void* event)
{
    display_image("255,0,255,0,255\n0,255,255,255,0\n255,255,255,255,255\n0,255,255,255,0\n255,0,255,0,255\n");
    sleep(1000);
    display_image("0,0,0,0,0\n0,0,0,0,0\n0,0,0,0,0\n0,0,0,0,0\n0,0,0,0,0\n");
}

void run_button_app()
{
    on_button_pressed(BUTTON_A, greet);
}

void run_weather_app()
{
    display_image("255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n");

    while(1) {
        char c = read_serial_char();
        if (c == 's') {
            display_image("255,0,255,0,255\n0,255,255,255,0\n255,255,255,255,255\n0,255,255,255,0\n255,0,255,0,255\n");
        } else if (c == 'r') {
            display_image("255,0,255,0,255\n255,0,255,0,255\n255,0,255,0,255\n255,0,255,0,255\n255,0,255,0,255\n");
        }
    }
}
