idf_component_register(
    SRCS "https.c"
    INCLUDE_DIRS "include"
    REQUIRES nvs_flash protocol_examples_common esp-tls
    EMBED_TXTFILES server_root_cert.pem
    )
