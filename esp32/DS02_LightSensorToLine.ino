/*
   Simple Light Sensor to Line
   modified for esp32 on January 2020
   modified by Digital Siam
*/
#include <TridentTD_LineNotify.h>
#define SSID        "thanatporn"
#define PASSWORD    "chompoo123"
#define LINE_TOKEN  "TOKEN"

void setup(){
 pinMode(2,INPUT_PULLUP);
 Serial.begin(115200);
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  delay(5000);
  Serial.println("program DS02");
  Serial.println("Simple Light Sensor to Line");
  Serial.println("modified for esp32"); 
  Serial.println("modified by Digital Siam");  
 Serial.println(LINE.getVersion());

}
void loop(){

 int d = digitalRead(2);  
 Serial.print("ค่าของแสงเป็น"+(String)d);
 Serial.println();
 LINE.setToken(LINE_TOKEN);
  LINE.notify("ค่าของแสงเป็น"+(String)d); 
 
 delay(3000);
  
}
