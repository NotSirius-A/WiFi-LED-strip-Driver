# WiFi-LED-strip-Driver

## Description
It is a device that controls programmable LED strips, user can adjust brightness and change programs through installed buttons or through the internet (WiFi).

## How does it work?
Device consists of an Arduino Nano (other boards will work too) and an ESP8266. Arduino is responsible for sending commands to the LED strip, handling data from ESP8266 and reacting to the on-board buttons. ESP8266 firstly connects to the local network via WiFi. Then it connects to the Adafruit.io servers (API), where user can select brightness and programs, which will be sent back to the ESP. User chosen data is forwarded to the Arduino, which adjusts an LED strip accordingly.

## Pictures of the inside
<img src='https://imgur.com/XxVWJjI.png'></img>
<img src='https://imgur.com/yJNNmqa.png'></img>
