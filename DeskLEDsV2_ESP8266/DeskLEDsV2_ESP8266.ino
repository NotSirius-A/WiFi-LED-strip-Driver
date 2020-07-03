/***************************** DEBUG *****************************/

boolean DEBUG = true;

/*************************** Libraries ***************************/

#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/********************* Software Serial Setup *********************/

const byte rxPin = 14; //D5
const byte txPin = 12; //D6
SoftwareSerial mySerial(rxPin, txPin);

/*********************** Wifi Access Point ***********************/

#define WLAN_SSID       "SSID"
#define WLAN_PASS       "PASSWORD"

/******************* Adafruit.io Setup ***************************/

#define AIO_SERVER    "io.adafruit.com"
#define AIO_SERVERPORT  1883                  // use 8883 for SSL
#define AIO_USERNAME  "AIO_USERNAME"
#define AIO_KEY       "AIO_KEY"

/*************** Wifi and AIO initialization *********************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/************************** Feeds *********************************/

#define subscribeFeed1 brightnessFeed
Adafruit_MQTT_Subscribe brightnessFeed = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/brightness"); // "/feeds/whateverYouSetOnTheSite"

#define subscribeFeed2 lightShowFeed
Adafruit_MQTT_Subscribe lightShowFeed = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/lightShow");

/*************************** Variables ***************************/

#define serialBaudRate 9600
#define mySerialBaudRate 9600

char message;

int brightness = 0;
int lightShow = 0;

int lastBrightness = 1;
int lastLightShow = 1;

/***************************** Misc *****************************/

void MQTT_connect(); //keep it, cause bugs

void setup(){
  
  initializeSerialCommunication(); //this function needs to be executed first, bc Serial.begin
  connectToWifi();

  mqtt.subscribe(&subscribeFeed1);

  mqtt.subscribe(&subscribeFeed2);
  
}

void loop(){
  // Ensure the connection to the MQTT server is alive (this will make the first
  // connection and automatically reconnect when disconnected).  
  MQTT_connect();

  getInfoFromSubscribtions(); //this consumes 250*numberOfSubcribtions milliseconds
  sendInfoToArduino();
  
  if(DEBUG){
    printInfoToConsoleDEBUG();
  }

  delay(25);
}
