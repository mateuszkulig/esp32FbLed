#include "led.h"

void led_display_rainbow(void)
/* display rainbow to test if led is ok */
{
    led_on(128, 0, 255);
    wait_ms(250);
    led_on(0, 0, 255);
    wait_ms(250);
    led_on(0, 255, 255);
    wait_ms(250);
    led_on(0, 255, 0);
    wait_ms(250);
    led_on(255, 255, 0);
    wait_ms(250);
    led_on(255, 128, 0);
    wait_ms(250);
    led_on(255, 0, 0);
    wait_ms(250);
    led_off();
}

void led_signal_status(uint8_t ok)
/* blink led in color red or green according to ok parameter */
{
    if(ok)
    {
        /* two greens to let know that everything is ok */
        wait_ms(500);
        led_on(0, 255, 0);
        wait_ms(500);
        led_off();
        wait_ms(500);
        led_on(0, 255, 0);
        wait_ms(500);
        led_off();
        wait_ms(500);
    }
}