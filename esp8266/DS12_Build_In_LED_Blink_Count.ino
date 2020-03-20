/*
   Flash Blink
   modified for esp8266 on January 2020
   modified by Digital Siam
*/

void setup() {
 Serial.begin(115200);
 pinMode(2, OUTPUT); 
 delay(5000);  
 Serial.println("program DS08");
 Serial.println("Flash Blink");
 Serial.println("modified for esp8266"); 
 Serial.println("modified by Digital Siam");
}
int cnt=0;
void loop() {
  digitalWrite(2,HIGH);
  delay(300);
  digitalWrite(2,LOW);
  cnt++;
  Serial.println("count="+(String)cnt);
  delay(300);
}
