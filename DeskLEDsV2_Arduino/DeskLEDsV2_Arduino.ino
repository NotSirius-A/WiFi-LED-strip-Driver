/***************************** DEBUG *****************************/

boolean DEBUG = true;

/*************************** Libraries ***************************/

#include <SoftwareSerial.h>
#include <FastLED.h>

/********************* Software Serial Setup *********************/

const byte rxPin = 6;
const byte txPin = 5;
SoftwareSerial mySerial(rxPin, txPin);

/*************************** Variables ***************************/

#define numberOfPrograms 3
#define serialBaudRate 9600
#define mySerialBaudRate 9600

#define LEDChipset WS2811
#define colorSet BRG
#define NUM_LEDS 14
#define DATA_PIN 12
#define UPDATES_PER_SECOND 50

#define brightnessButtonPin 2
#define lightShowButtonPin  3

//support variables
int lastFirstSerialRead = 0;
int lastSecondSerialRead = 0;

int lastFirstButtonRead = 1;
int lastSecondButtonRead = 1;
bool addToFirstButtonRead;
bool addToSecondButtonRead;

int firstNumOfTimes = 0;
int secondNumOfTimes = 0;

//actual variables
int brightness;
int lightShow;

/***************************** LED Settings ************************/

CRGB leds[NUM_LEDS];

/*******************************************************************/

void setup(){
 
  initializeSerialCommunication(); //this function needs to be executed first, bc Serial.begin

  initializeLEDs();

  initializeButtons(brightnessButtonPin, lightShowButtonPin);

}

void loop(){

  mySerial.write("."); //ping an ESP, beacuse if they wont turn on at the same time ESP will have problems with mySerial.available() > 0

  if(mySerial.available() > 0){
    recieveInfoFromESP();
  }

  brightness = constrain(brightness, 0, 255); //just for protection, probably not needed
  lightShow = constrain(lightShow, 1, numberOfPrograms); 

  readButtons(brightnessButtonPin, lightShowButtonPin);
  updateButtonFeeds();

  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; //chage color in built-in palettes
  
  fillLEDs(startIndex); 
  
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);

  if(DEBUG){
    printInfoToConsoleDEBUG(); 
  }
}
