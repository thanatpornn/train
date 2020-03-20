/*
   LED Count When Dark to Line
   modified for esp32 on January 2020
   modified by Digital Siam
*/

int x1=0;
int x=0;
int cnt=0;
#include <TridentTD_LineNotify.h>
#define SSID        "WIFI"
#define PASSWORD    "PASSWORD"
#define LINE_TOKEN  "TOKEN"
void setup(){
 Serial.begin(115200);
 Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
    Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  
 pinMode(2,INPUT_PULLUP);
 delay(5000);
 Serial.println("program DS15");
 Serial.println("LED Count When Dark to Line");
 Serial.println("modified for esp32"); 
 Serial.println("modified by Digital Siam");
 pinMode(0,OUTPUT);
}

void loop(){
   LINE.setToken(LINE_TOKEN); 
 digitalWrite(0, LOW); 
 int a = digitalRead(2);
 Serial.println(a);  

if (a == 0){
  x = 0;
  }
  else {
    x = 1;
  }
  if (x!=0){
     digitalWrite(0, HIGH); 
  }
  
if(x>x1){
  cnt++;
  LINE.notify("มืดครั้งที่ = "+(String)cnt); 
  Serial.println("มืดครั้งที่ = "+(String)cnt);
 }  
 x1=x;
 
 
 delay(300);

}
