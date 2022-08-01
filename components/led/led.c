#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

#include "led_display.h"


static const char *TAG = "led";

static led_strip_t *pStrip_a;

void configure_led(void)
/* configure built-in led to be usable in code */
{
    ESP_LOGI(TAG, "Program switching built-in led's color from messenger");
    /* LED strip initialization with the GPIO and pixels number*/
    pStrip_a = led_strip_init(CONFIG_BLINK_LED_RMT_CHANNEL, CONFIG_BLINK_GPIO, 1);
    /* Set all LED off to clear all pixels */
    pStrip_a->clear(pStrip_a, 50);
    led_display_rainbow();
}

void wait_ms(uint32_t timems) 
{
    /* wait for timems miliseconds to pass */
    vTaskDelay(timems / portTICK_PERIOD_MS);
}

void led_on(uint8_t r, uint8_t g, uint8_t b)
/* turn the led on with color defined by rgb values */
{
    ESP_LOGI(TAG, "turning the led on, colored (%d, %d, %d)rgb!", r, g, b);
    /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
    pStrip_a->set_pixel(pStrip_a, 0, r, g, b);
    /* Refresh the strip to send data */
    pStrip_a->refresh(pStrip_a, 100);
}

void led_off(void)
/* turn the led off */
{
    ESP_LOGI(TAG, "turning the led off");
    /* Set all LED off to clear all pixels */
    pStrip_a->clear(pStrip_a, 50);
}


