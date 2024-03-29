#include "stdio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_http_client.h"
#include "sdkconfig.h"

#define TAG_NETWORK             "network"
#define DEFAULT_SSID            CONFIG_WIFI_SSID
#define DEFAULT_PWD             CONFIG_WIFI_PASSWORD
#define DEFAULT_SCAN_METHOD     WIFI_FAST_SCAN
#define DEFAULT_SORT_METHOD     WIFI_CONNECT_AP_BY_SIGNAL
#define DEFAULT_RSSI            -127
#define DEFAULT_AUTHMODE        WIFI_AUTH_OPEN

/**
 * @brief               Check the status of the connection or change it
 *                      Needed as a callback in callback in fast_scan instance register
 * 
 * @param change        0 or 1, whether a connection should be set to connected
 * @return uint8_t      0 for disconnected/connecting, 1 for connected
 */
uint8_t connectionStatus(uint8_t change);

/**
 * @brief               Callback needed by esp_event_handler_instance_register function
 *                      I dont know what parameters are, there are not documented anywhere but used in examples.
 *                      Calls connectionStatus(1) after connecting to wifi.
 * 
 * @param arg           ?
 * @param event_base    ?
 * @param event_id      ?
 * @param event_data    ?
 */
static void eventHandler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data);

/**
 * @brief               Initialize Wi-Fi as sta and set scan method
 * 
 */
static void fastScan(void);

/**
 * @brief               Connect to wifi with default SSID and password
 * 
 */
void connectWiFi(void);
