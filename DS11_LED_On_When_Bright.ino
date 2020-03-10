/*
   LED On When Dark
   modified for esp8266 on January 2020
   modified by Digital Siam
*/

void setup(){
 Serial.begin(115200);
 pinMode(2,INPUT_PULLUP);

 delay(5000);
 Serial.println("program DS10");
 Serial.println("LED On When Dark");
 Serial.println("modified for esp8266"); 
 Serial.println("modified by Digital Siam");
 pinMode(0,OUTPUT);
}

void loop(){
 int d = analogRead(2);
 Serial.println(d);  
 digitalWrite(0, LOW); 
if (d == 0){
 digitalWrite(0, HIGH);
  }
 delay(300);
}
