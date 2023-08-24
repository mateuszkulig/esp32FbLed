#include "https.h"

static void httpsGetRequest(esp_tls_cfg_t cfg)
{
    char buf[512];
    int ret, len;

    struct esp_tls *tls = esp_tls_conn_http_new(WEB_URL, &cfg);

    if (tls != NULL) {
        ESP_LOGI(TAG_HTTPS, "Connection established...");
    } else {
        ESP_LOGE(TAG_HTTPS, "Connection failed...");
        goto exit;
    }

    size_t written_bytes = 0;
    do {
        ret = esp_tls_conn_write(tls,
                                 REQUEST + written_bytes,
                                 sizeof(REQUEST) - written_bytes);
        if (ret >= 0) {
            ESP_LOGI(TAG_HTTPS, "%d bytes written", ret);
            written_bytes += ret;
        } else if (ret != ESP_TLS_ERR_SSL_WANT_READ  && ret != ESP_TLS_ERR_SSL_WANT_WRITE) {
            ESP_LOGE(TAG_HTTPS, "esp_tls_conn_write  returned: [0x%02X](%s)", ret, esp_err_to_name(ret));
            goto exit;
        }
    } while (written_bytes < sizeof(REQUEST));

    ESP_LOGI(TAG_HTTPS, "Reading HTTP response...");

    do {
        len = sizeof(buf) - 1;
        bzero(buf, sizeof(buf));
        ret = esp_tls_conn_read(tls, (char *)buf, len);

        if (ret == ESP_TLS_ERR_SSL_WANT_WRITE  || ret == ESP_TLS_ERR_SSL_WANT_READ) {
            continue;
        }

        if (ret < 0) {
            ESP_LOGE(TAG_HTTPS, "esp_tls_conn_read  returned [-0x%02X](%s)", -ret, esp_err_to_name(ret));
            break;
        }

        if (ret == 0) {
            ESP_LOGI(TAG_HTTPS, "connection closed");
            break;
        }

        len = ret;
        ESP_LOGD(TAG_HTTPS, "%d bytes read", len);
        /* Print response directly to stdout as it is read */
        for (int i = 0; i < len; i++) {
            putchar(buf[i]);
        }
        putchar('\n'); // JSON output doesn't have a newline at end
    } while (1);

exit:
    esp_tls_conn_delete(tls);
    for (int countdown = 10; countdown >= 0; countdown--) {
        ESP_LOGI(TAG_HTTPS, "%d...", countdown);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

static void httpsRequestTask(void *pvparameters)
{
    ESP_LOGI(TAG_HTTPS, "https_request using crt bundle");
    esp_tls_cfg_t cfg = {
        .crt_bundle_attach = esp_crt_bundle_attach,
    };
    httpsGetRequest(cfg);
    vTaskDelete(NULL);  // stop from looping
}

void sendRequest(void)
{
    xTaskCreate(&httpsRequestTask, "https_get_task", 8192, NULL, 5, NULL);
}
