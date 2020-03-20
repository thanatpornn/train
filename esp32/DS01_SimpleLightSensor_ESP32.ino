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
 Serial.println("modified for esp32"); 
 Serial.println("modified by Digital Siam");

}
int d1=0;
void loop(){
 int d = digitalRead(2);  
 if(d==0){d1=0;}
 if(d==1){d1=4095;}  
 Serial.print("ค่าของแสงเป็น"+(String)d1);
 Serial.println();
 delay(300);
  
}
