/*
   WIFI Switch LED
   modified for esp32 on January 2020
   modified by Digital Siam
*/
#include <WiFi.h>
 
const char* ssid     = "itdabos_wifi2.4G";
const char* password = "0819110933";
 
WiFiServer server(80);
 
void setup()
{
  Serial.begin(115200);
  delay(5000);
 Serial.println("program DS21");
 Serial.println("WIFI Switch LED");
 Serial.println("modified for esp32"); 
 Serial.println("modified by Digital Siam");
  pinMode(12, OUTPUT);      // set the LED pin mode
  pinMode(13, OUTPUT);      // set the LED pin mode
  pinMode(14, OUTPUT);      // set the LED pin mode
  pinMode(15, OUTPUT);      // set the LED pin mode
 
  delay(10);
 
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 
  server.begin();
 
}
 
int value = 0;
 
void loop() {
  WiFiClient client = server.available();   // listen for incoming clients
 
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
 
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
 
            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/12H\">here</a> to turn the LED on pin 12 on.<br>");
            client.print("Click <a href=\"/12L\">here</a> to turn the LED on pin 12 off.<br>");
            client.print("<br>");
 
            client.print("Click <a href=\"/13H\">here</a> to turn the LED on pin 13 on.<br>");
            client.print("Click <a href=\"/13L\">here</a> to turn the LED on pin 13 off.<br>");
            client.print("<br>");
 
            client.print("Click <a href=\"/14H\">here</a> to turn the LED on pin 14 on.<br>");
            client.print("Click <a href=\"/14L\">here</a> to turn the LED on pin 14 off.<br>");
            client.print("<br>");
 
            client.print("Click <a href=\"/15H\">here</a> to turn the LED on pin 15 on.<br>");
            client.print("Click <a href=\"/15L\">here</a> to turn the LED on pin 15 off.<br>");
            client.print("<br>");
 
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
 
        // Check to see if the client request was "GET /xH" or "GET /xL":
        if (currentLine.endsWith("GET /12H")) {
          digitalWrite(12, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /12L")) {
          digitalWrite(12, LOW);                // GET /L turns the LED off
        }
 
        if (currentLine.endsWith("GET /13H")) {
          digitalWrite(13, HIGH);               // GET /H turns the LED on
        }
 
        if (currentLine.endsWith("GET /13L")) {
          digitalWrite(13, LOW);                // GET /L turns the LED off
        }
 
        if (currentLine.endsWith("GET /14H")) {
          digitalWrite(14, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /14L")) {
          digitalWrite(14, LOW);                // GET /L turns the LED off
        }
 
        if (currentLine.endsWith("GET /15H")) {
          digitalWrite(15, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /15L")) {
          digitalWrite(15, LOW);                // GET /L turns the LED off
        }
 
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
