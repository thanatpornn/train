/*
   Bluid-In Flash Blink
   modified for esp32 on January 2020
   modified by Digital Siam
*/

void setup() {
 Serial.begin(115200);
 pinMode(4, OUTPUT); 
 delay(5000);  
 Serial.println("program DS08");
 Serial.println("Bluid-In Flash Blink");
 Serial.println("modified for esp32"); 
 Serial.println("modified by Digital Siam");
}

void loop() {
  digitalWrite(4,HIGH);
  delay(300);
  digitalWrite(4,LOW);
  delay(300);
}
