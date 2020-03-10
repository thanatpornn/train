void setup(){
 Serial.begin(115200);
 pinMode(15,INPUT);
 pinMode(2,OUTPUT);
}
void loop(){
 int d = digitalRead(15);  
 digitalWrite(2, d);
 Serial.print(d,DEC);
 Serial.println();
 delay(300);
  
}
