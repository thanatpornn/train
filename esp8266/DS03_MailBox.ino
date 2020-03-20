/*
   MailBox
   modified for esp32 on January 2020
   modified by digitalsiam
*/
#include <TridentTD_LineNotify.h>

#define SSID        "itdabos_wifi2.4G"
#define PASSWORD    "0819110933"
#define LINE_TOKEN  "QsQ98UigZ6hSi5Hub50J1HGNyDo2dmB7rdE5OE7s7BO"

int d1=0;

void setup(){
 Serial.begin(115200);
 pinMode(2,INPUT_PULLUP);
 delay(5000);
 Serial.println("program DS03");
 Serial.println("MailBox");
 Serial.println("modified for esp32"); 
 Serial.println("modified by digital siam");
 Serial.println(LINE.getVersion());
 WiFi.begin(SSID, PASSWORD);
 Serial.printf("WiFi connecting to %s\n",  SSID);
 while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
 Serial.printf("\nWiFi connected\nIP : ");
 Serial.println(WiFi.localIP());
}

void loop(){
 LINE.setToken(LINE_TOKEN); 
 int d = digitalRead(2);
if(d1>d){
  Serial.println("มีจดหมายเข้า");
  LINE.notify("มีจดหมายเข้า");
 }  
 d1=d;

 
 delay(300);

  
}
