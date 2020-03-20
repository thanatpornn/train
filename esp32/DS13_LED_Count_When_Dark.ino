/*
   LED Count When Dark
   modified for esp32 on January 2020
   modified by Digital Siam
*/
int d1=0;
int cnt=0;

void setup(){
 Serial.begin(115200);
 pinMode(2,INPUT_PULLUP);

 delay(5000);
 Serial.println("program DS13");
 Serial.println("LED Count When Dark");
 Serial.println("modified for esp32"); 
 Serial.println("modified by Digital Siam");
 pinMode(0,OUTPUT);
}

void loop(){
 int d = digitalRead(2);
 Serial.println(d);  
 digitalWrite(0, LOW); 
if (d > 0){
 digitalWrite(0, HIGH);
  }
if(d>d1){
  cnt++;
   Serial.println("มืดครั้งที่ = "+(String)cnt);
 }  
 d1=d;

 delay(300);

}
