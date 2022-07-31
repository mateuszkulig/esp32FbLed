idf_component_register(SRCS "led.c" "led_display.c"
                    REQUIRES led_strip
                    INCLUDE_DIRS "include")