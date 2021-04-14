# WiFi-LED-strip-Driver

## Description
It is a device that controls programmable LED strips, user can adjust brightness and change programs through installed buttons or through the internet (WiFi).

## How does it work?
Device consists of an Arduino Nano (other boards will work too) and an ESP8266 breakout board. Arduino is responsible for sending commands to the LED strip, handling data from ESP8266 and reacting to the on-board buttons. <br>
ESP8266: Firstly connects to the local network via WiFi. Then it connects to the Adafruit.io servers (API), where user, through an internet browser, can select brightness and programs, which will be sent back to the ESP. User chosen data is forwarded to the Arduino, which adjusts an LED strip accordingly.

## Pictures of the inside
<img src='https://imgur.com/XxVWJjI.png'></img>
<img src='https://imgur.com/yJNNmqa.png'></img>

## Notes
- It has been around 10 months since I've installed it under my desk (10 months of continuous operation). The LED driver and the LED's themselves still perform perfectly well
