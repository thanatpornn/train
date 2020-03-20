/*
   LED Blink
   modified for esp8266 on January 2020
   modified by Digital Siam
*/

void setup() {
 Serial.begin(115200);
 pinMode(0, OUTPUT); 
 delay(5000);  
 Serial.println("program DS09");
 Serial.println("LED Blink");
 Serial.println("modified for esp8266"); 
 Serial.println("modified by Digital Siam");
}
int cnt=0;
void loop() {
  digitalWrite(0,HIGH);
  delay(300);
  digitalWrite(0,LOW);
  cnt++;
  Serial.println("count="+(String)cnt);
  delay(300);
}
