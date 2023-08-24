#include "string.h"
#include "stdlib.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "esp_netif.h"
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/netdb.h"
#include "lwip/dns.h"
#include "esp_tls.h"
#include "esp_crt_bundle.h"

#define TAG_HTTPS "https"
#define WEB_SERVER "graph.facebook.com"
#define WEB_PORT "443"
#define WEB_URL ""
#define ACCESS_TOKEN ""
#define PAGE_ID ""

// Standard request boilerplate
static const char REQUEST[] =   "GET "      WEB_URL     " HTTP/1.1\r\n"
                                "Host: "    WEB_SERVER  "\r\n"
                                "User-Agent: esp-idf/1.0 esp32\r\n"
                                "\r\n";

// Certificate stuff
extern const uint8_t server_root_cert_pem_start[]   asm("_binary_server_root_cert_pem_start");
extern const uint8_t server_root_cert_pem_end[]     asm("_binary_server_root_cert_pem_end");

static void httpsGetRequest(esp_tls_cfg_t cfg);

static void httpsRequestTask(void *pvparameters);

void sendRequest(void);
