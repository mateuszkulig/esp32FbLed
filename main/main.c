#include "stdio.h"
#include "esp_log.h"

#include "led.h"
#include "network.h"
#include "https.h"

#define TAG_MAIN "main"

/**
 * @brief   Function always running first after startup
 * @note    configure_led function should have different naming
 * 
 */
void startupSequence(void) {
    // Initialize NVS (possibly needed for fastScan function call)
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Initialize stuff needed for https component
    ESP_ERROR_CHECK(esp_netif_init());

    // Display rainbow on startup to test led
    configure_led();

    // Connect to the wifi
    connectWiFi();
}

/**
 * @brief   Entry point for ESP-IDF
 *          The name cannot to be changed to camelCase because framework is searching the function with this exact name
 * 
 */
void app_main(void)
{
    startupSequence();
    // sendRequest();
    
}
