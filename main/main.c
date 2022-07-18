#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

static const char *TAG = "boobs";

static led_strip_t *pStrip_a;


static void led_on(uint8_t r, uint8_t g, uint8_t b)
{
    ESP_LOGI(TAG, "turning the led on, colored (%d, %d, %d)rgb!", r, g, b);
    /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
    pStrip_a->set_pixel(pStrip_a, 0, r, g, b);
    /* Refresh the strip to send data */
    pStrip_a->refresh(pStrip_a, 100);
}

static void led_off(void) {
    ESP_LOGI(TAG, "turning the led off");
    /* Set all LED off to clear all pixels */
    pStrip_a->clear(pStrip_a, 50);
}



void app_main(void)
{
    /* Configure the peripheral according to the LED type */
    configure_led();
    for(uint8_t i=0; i<10; i++) {
        led_on(255, 26, 140);
        wait_ms(500);
        led_off();
        wait_ms(500);
    }
}
