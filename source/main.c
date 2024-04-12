#include "bridge.h"

int main()
{
    microbit_init();

    while(1) {
        display("..--^^--..");
    }

    microbit_panic( 123 );
}

