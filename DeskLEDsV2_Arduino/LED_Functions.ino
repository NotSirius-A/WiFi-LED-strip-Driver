void initializeLEDs(){
  FastLED.addLeds<LEDChipset, DATA_PIN, colorSet>(leds, NUM_LEDS); 

  if(DEBUG){
    Serial.println();
    Serial.println("LEDs initialized");
    Serial.println();
  }
  
}

void fillLEDs(uint8_t colorIndex){
//here basically just call a function handling all that gross LED coding
//it's designed to just not care about anything in the actual program settings related, only number of them is important
//if you need more just copy and paste case X: fillLEDsFromProgramX, and code it separately
//colorIndex only needed for programs using palettes

  FastLED.setBrightness(brightness);
  uint8_t brightness = 255; //idk what that means, but it was in a sketch

  switch(lightShow){
    case 1:
      fillLEDsFromProgram1(colorIndex);
      break;
    case 2:
      fillLEDsFromProgram2(colorIndex);
      break;
    case 3:
      fillLEDsFromProgram3(colorIndex);
      break;
  }
  
}
