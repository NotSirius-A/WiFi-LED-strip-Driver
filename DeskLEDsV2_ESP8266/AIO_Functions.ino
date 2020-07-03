void getInfoFromSubscribtions(){

  Adafruit_MQTT_Subscribe *subscription;

  //this function's argument represents time
  while ((subscription = mqtt.readSubscription(150))) { 
    if (subscription == &subscribeFeed1) {
    }
  }

  while ((subscription = mqtt.readSubscription(150))) {
    if (subscription == &subscribeFeed2) {
    }
  }

  brightness = atoi((const char*) subscribeFeed1.lastread);
  lightShow = atoi((const char*) subscribeFeed2.lastread);
  //if you want to change these subscribitons, just change variables here
  //everything else is automatic. If you want to add more just copy and paste this template
  
}

void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0) {
    // basically die and wait for WDT to reset me
     while (1);
    }
  }
  Serial.println("MQTT Connected!");
}
