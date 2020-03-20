/*
   Simple Light Sensor to Line
   modified for esp8266 on January 2020
   modified by Digital Siam
*/
#include <TridentTD_LineNotify.h>

#define SSID        "itdabos_wifi2.4G"
#define PASSWORD    "0819110933"
#define LINE_TOKEN  "QsQ98UigZ6hSi5Hub50J1HGNyDo2dmB7rdE5OE7s7BO"

void setup(){
 Serial.begin(115200);
  Serial.println(LINE.getVersion());
  
  WiFi.begin(SSID, PASSWORD);
   delay(5000);
  Serial.println("program DS02");
  Serial.println("Simple Light Sensor to Line");
  Serial.println("modified for esp8266"); 
  Serial.println("modified by Digital Siam");
  pinMode(2,INPUT_PULLUP);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  
 

}
void loop(){
  LINE.setToken(LINE_TOKEN);
 int d = analogRead(2);  
 Serial.print("ค่าของแสงเป็น"+(String)d);
 Serial.println();
  LINE.notify("ค่าของแสงเป็น"+(String)d); 
 
 delay(300);
  
}
