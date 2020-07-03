void initializeSerialCommunication(){
  if(DEBUG){  

    Serial.begin(serialBaudRate); 

    mySerial.begin(mySerialBaudRate);
    
    Serial.println("Estalishing serial communication");
    while(!mySerial.available()){
      mySerial.write('.'); //ping an arduino
      Serial.print(".");
      delay(100);
    }
   Serial.println();
   Serial.println("Serial communication established");
  }else {

    mySerial.begin(mySerialBaudRate);
    
    while(!mySerial.available()){
      mySerial.write('.');
      delay(25);
    }
  }
}

void sendInfoToArduino(){
 
  if(brightness != lastBrightness){
  //these weird math operations to ensure I am using valid characters
    for(int i = 0; i < 5; i++){
      mySerial.write(char((brightness/5) +80));
      lastBrightness = brightness;
      delay(5);
    }
  }

  if(lightShow != lastLightShow){
    for(int i = 0; i < 5; i++){ 
      mySerial.write(char(lightShow+70));
      lastLightShow = lightShow;
      delay(5);
    }
  }
  
 
}
