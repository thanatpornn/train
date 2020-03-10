/*
   Bright Count
   modified for esp8266 on January 2020
   modified by digitalsiam
*/
int d1=0;
int cnt=0;
void setup(){
 Serial.begin(115200);
 pinMode(2,INPUT_PULLUP);
 delay(5000);
 Serial.println("program DS03");
 Serial.println("Bright Count");
 Serial.println("modified for esp8266"); 
 Serial.println("modified by digital siam");

}

void loop(){
 int d = digitalRead(2);
if(d1>d){
  cnt++;
 }  
 d1=d;

 Serial.println("แสงสว่างครั้งที่ = "+(String)cnt);
 delay(300);

  
}
