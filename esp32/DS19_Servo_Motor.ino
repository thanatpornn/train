/*
   Servo Motor
   modified for esp32 on January 2020
   modified by Digital Siam
*/
#include <ESP32Servo.h>

Servo myservo; 

int pos = 0;    

void setup() {
  myservo.attach(13); 
  delay(5000);
  Serial.println("program DS19");
  Serial.println("Servo Motor");
  Serial.println("modified for esp32"); 
  Serial.println("modified by Digital Siam");  
}

void loop() {
  for (pos = 0; pos <= 120; pos += 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 120; pos >= 0; pos -= 1) { 
    myservo.write(pos);             
    delay(15);                      
  }
}
