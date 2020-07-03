void connectToWifi(){
  if(DEBUG){
    Serial.println(); Serial.println();
    Serial.print("Connecting to ");
    Serial.println(WLAN_SSID);

    WiFi.begin(WLAN_SSID, WLAN_PASS);
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.print(".");
    }
    Serial.println();
    Serial.println("WiFi connected");
    Serial.println("IP address: "); 
    Serial.println(WiFi.localIP());
    Serial.println();
  }else {
    while (WiFi.status() != WL_CONNECTED) {
      delay(100);
    }
  }
  
}


void printInfoToConsoleDEBUG(){

  Serial.print("brightness = ");
  Serial.println(brightness);
  Serial.print("lightShow = ");
  Serial.println(lightShow);
  Serial.println("------------------------------------");
  Serial.println();
  
}
