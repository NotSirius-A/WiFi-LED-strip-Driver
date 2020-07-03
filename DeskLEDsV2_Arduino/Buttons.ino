//no need to touch this unless you need to change number of buttons
void initializeButtons(int firstButtonPin, int secondButtonPin){
  pinMode(firstButtonPin, INPUT_PULLUP);
  pinMode(secondButtonPin, INPUT_PULLUP);

  if(DEBUG){
    Serial.println();
    Serial.println("Buttons initialized");
    Serial.println();
  }
}

//no need to touch this unless you need to change number of buttons
void readButtons(int firstButtonPin, int secondButtonPin){
  int firstButtonRead = digitalRead(firstButtonPin);
  int secondButtonRead = digitalRead(secondButtonPin);

  
  if(firstButtonRead != lastFirstButtonRead && firstButtonRead < lastFirstButtonRead){
    addToFirstButtonRead = 1;
  }

  if(secondButtonRead != lastSecondButtonRead && secondButtonRead < lastSecondButtonRead){
    addToSecondButtonRead = 1;
  }

  lastFirstButtonRead = firstButtonRead;
  lastSecondButtonRead = secondButtonRead;
  
}


//this needs to be changed if you are changing variables: brightness and lightShow
void updateButtonFeeds(){

  if(addToFirstButtonRead){
    brightness = brightness + 51;
    addToFirstButtonRead = 0;
    if(brightness > 255){
      brightness = 0;
    }
  }

  if(addToSecondButtonRead){
    lightShow++;
    addToSecondButtonRead = 0;
    if(lightShow > numberOfPrograms){
      lightShow = 1;
    }
  }
  
}
