/*
   Potentiometer with Servo Motor
   modified for esp32 on January 2020
   modified by Digital Siam
*/
#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup(){
 Serial.begin(115200);
 pinMode(14,INPUT);
 myservo.attach(13);  
   delay(5000);
  Serial.println("program DS20");
  Serial.println("Potentiometer with Servo Motor");
  Serial.println("modified for esp32"); 
  Serial.println("modified by Digital Siam");  
}
void loop(){
 int d = analogRead(14);  
 int a = d * 90 / 4095;
 Serial.print(d,DEC);
 Serial.print(" ");
 Serial.print(a,DEC);
 Serial.println(".");
 myservo.write(a);
 //delay(300);

  
}
