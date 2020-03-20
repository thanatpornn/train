/*
   External LED Blink
   modified for esp32 on January 2020
   modified by Digital Siam
*/

void setup() {
 Serial.begin(115200);
 pinMode(0, OUTPUT); 
 delay(5000);  
 Serial.println("program DS09");
 Serial.println("External LED Blink");
 Serial.println("modified for esp32"); 
 Serial.println("modified by Digital Siam");
}

void loop() {
  digitalWrite(0,HIGH);
  delay(300);
  digitalWrite(0,LOW);
  delay(300);
}
