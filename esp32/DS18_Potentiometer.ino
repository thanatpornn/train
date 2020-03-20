/*
   Potentiometer
   modified for esp32 on January 2020
   modified by Digital Siam
*/
void setup(){
 Serial.begin(115200);
 pinMode(13,INPUT);
  delay(5000);
  Serial.println("program DS18");
  Serial.println("Potentiometer");
  Serial.println("modified for esp32"); 
  Serial.println("modified by Digital Siam");  
}
void loop(){

 int d = analogRead(13);  
 Serial.print(d,DEC);
 Serial.println(".");

 delay(1000);

}
