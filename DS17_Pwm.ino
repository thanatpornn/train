void setup() {
  ledcAttachPin(4, 1);

  ledcSetup(1,100000, 12);

}

void loop() {
   for(int i=0; i<60; i+=15) {

    ledcWrite(1, i);
    //Serial.print(i);
    //Serial.print("test");
    delay(500);

  }

}
