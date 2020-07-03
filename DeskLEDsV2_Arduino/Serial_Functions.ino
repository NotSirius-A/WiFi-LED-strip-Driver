void initializeSerialCommunication(){
  if(DEBUG){  

    Serial.begin(serialBaudRate); 

    mySerial.begin(mySerialBaudRate);
    
    Serial.println("Estalishing serial communication");
    while(!mySerial.available()){
      mySerial.write('.'); //ping an ESP
      Serial.print(".");
      delay(100);
    }
   Serial.println(); 
   Serial.println("Serial communication established");
  }else {

    mySerial.begin(mySerialBaudRate);
    
    while(!mySerial.available()){
      mySerial.write('.');
      delay(50);
    }
  }
}


void recieveInfoFromESP(){
  char message;
  int recievedInt = 0;
  int firstSerialRead;
  int secondSerialRead;

  if(mySerial.available() > 0){
  message = mySerial.read();
  recievedInt = int(message);
  }
  //basically don't update lightShow and brightness unless there's been change in value
  //that lets me use automatically switch beetween button control on WiFi control
  
  //there's a bug that sometimes recievedInt is negative (some noise probably), but in the next step it will be filtered
  
  if(recievedInt >= 80 && recievedInt <= 100 ){
    firstSerialRead = map((recievedInt-80)*5, 0, 100, 0, 255);
  }else if(recievedInt > 70 && recievedInt <= numberOfPrograms+70) {
    secondSerialRead = recievedInt-70;
  } 

  if(firstSerialRead != lastFirstSerialRead){
    brightness = firstSerialRead;
    lastFirstSerialRead = firstSerialRead;
  }

  if(secondSerialRead != lastSecondSerialRead){
    lightShow = secondSerialRead;
    lastSecondSerialRead = secondSerialRead;
  }

}
