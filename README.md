# vMix M5Stick-C Tally Light

![](working-example.gif)

## Getting started

### Step 1
1.1 Follow the tutorial on the [M5Stack website](https://docs.m5stack.com/#/en/arduino/arduino_development).

1.2 Copy the libraries that are used by this project (found in the `libs` folder) to your system.
The default path is: `%userprofile%\Documents\Arduino\libraries`

### Step 2
Change the following variables to your specific environment (found in `a_GLOBAL.ino`):
*  WIFI_SSID
*  WIFI_PASS
*  VMIX_IP
*  VMIX_PORT (default: 8099)
*  TALLY_NR (What input number should the Tally listen to, default: 0)

### Step 3
Upload to your device and check if it works.

## TODO
* [x]  Press on M5 button will display IP Address for easy access
* [ ]  Webserver for easy configuration
* [ ]  Access Point mode when not connected to a WiFi network
* [ ]  Save the data to the EEPROM
* [ ]  When vMix closes, show on LCD

### Good to know
This is my very first C-project, if you have any suggestions on how to improve the code, please let me know.

#### Thanks
A massive thanks to [Thomas Mout](https://github.com/ThomasMout) for creating [Arduino vMix Tally](https://github.com/ThomasMout/Arduino-vMix-tally). This project is an extended version of his.
