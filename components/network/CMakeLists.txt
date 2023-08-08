idf_component_register(SRCS "network.c"
                    REQUIRES nvs_flash esp_http_client
                    INCLUDE_DIRS "include")
