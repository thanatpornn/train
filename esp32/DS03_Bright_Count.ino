/*
   Bright Count
   modified for esp32 on January 2020
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
 Serial.println("modified for esp32"); 
 Serial.println("modified by Digital Siam");

}

void loop(){
 int d = digitalRead(2);
if(d1>d){
  cnt++;
   Serial.println("แสงสว่างครั้งที่ = "+(String)cnt);
 }  
 d1=d;


 delay(300);

  
}
