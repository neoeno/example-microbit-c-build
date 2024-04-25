#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#define BUTTON_A 1
#define BUTTON_B 2

EXTERNC void microbit_init(void);
EXTERNC void microbit_panic(int statusCode);
EXTERNC void display(char message[]);
EXTERNC void display_image(char image[]);
EXTERNC void sleep(int milliseconds);
EXTERNC char read_serial_char(void);
EXTERNC void on_button_pressed(int button, void (*callback)(void*));

#undef EXTERNC
