/*
   Simple Light Sensor
   modified for esp8266 on January 2020
   modified by Digital Siam
*/

void setup(){
 Serial.begin(115200);
 pinMode(2,INPUT_PULLUP);
 delay(5000);
 Serial.println("program DS01");
 Serial.println("Simple Light Sensor");
 Serial.println("modified for esp8266"); 
 Serial.println("modified by Digital Siam");

}
void loop(){
 int d = analogRead(2);  
 Serial.print("ค่าของแสงเป็น"+(String)d); 
 Serial.println();
 delay(300);
  
}
