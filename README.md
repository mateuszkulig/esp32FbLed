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
