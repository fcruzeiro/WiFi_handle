#include <WiFi_Setup.h>
#include <ESP8266WiFi.h>




void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
WiFi_init();
}

void loop() {
server.handleClient();

//delay(2000);
//Serial.println(WiFi.localIP());
//
}
