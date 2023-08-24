# esp32FbLed

Changing the state of onboard esp32s3 rgb led from messenger

## How to build & run

It is recommended to install and use ESP-IDF plugin for VSCode, but you can also compile from command line using instructions from [ESP-IDF documentation](https://docs.espressif.com/projects/esp-idf/en/v5.1/esp32s3/api-guides/build-system.html).

With the help of the plugin it should be as easy as running couple of macros from VSCode command palette (default Ctrl+Shift+P):

1. `ESP-IDF: Select port to use (COM, tty, usbserial)` > Try every port until you get the right one
2. `ESP-IDF: Set Espressif device target` > Select your board
3. `ESP-IDF: Build, Flash and start a monitor on your device`
4. Done! The code should be running by now

You can also run last macro using buttons from panel at the bottom of VSCode with the plugin installed.

If after these steps you are still facing build problems you might try to create plugin data in the workspace:

5. `ESP-IDF: Add vscode configuration folder`
6. `ESP-IDF: Configure ESP-IDF extension` > Select any setup options

## Configuration

### WiFi

In order to use main WiFi-dependent feature you must set WiFi SSID and password in the network component config file.

You can find it in `./components/network/Kconfig.projbuild`. Replace the `<your ssid here>` and `<your password here>` with actual connect data (do NOT leave `<>`).
After that you should see `Connected` after few seconds in the ESP-IDF monitor output when run.

### Certificate

HTTPS conneciton requires you to have certificate from [Facebook](https://www.facebook.com/). It is included in this repo, and I will try to update is when it expires, but in case i forgot, you can generate it yourself. The PEM file was extracted from the output of this command:

```
    openssl s_client -showcerts -connect www.facebook.com:443 </dev/null
```

The CA root cert is the last cert given in the chain of certs. Just copy and paste its contents into `./components/https/server_root_cert.pem`.
