#include <stdio.h>
#include "esp_log.h"
#include "sdkconfig.h"

#include "led.h"

static const char *TAG = "boobs";

/**
 * @brief   Function always running first after startup
 * @note    configure_led function should have different naming
 * 
 */
void startupSequence(void) {
    /* display rainbow on startup to test led */
    configure_led();
}

/**
 * @brief   Entry point for ESP-IDF
 *          The name cannot to be changed to camelCase because framework is searching the function with this exact name
 * 
 */
void app_main(void)
{
    /* Configure the peripheral according to the LED type */
    startupSequence();
}
