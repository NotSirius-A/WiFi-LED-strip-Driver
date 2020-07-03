/***** Basic rainbow *****/
void fillLEDsFromProgram1(uint8_t colorIndex){
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(RainbowColors_p, colorIndex, brightness, LINEARBLEND);
    colorIndex += 3;
  }
}

/***** White *****/
void fillLEDsFromProgram2(uint8_t colorIndex){
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
}

/***** Purple *****/
void fillLEDsFromProgram3(uint8_t colorIndex){
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(120, 0, 200);
  }
}
