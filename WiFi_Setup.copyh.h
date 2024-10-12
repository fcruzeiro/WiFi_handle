/*Esse é o que esta usando 



*/
#ifndef WIFI_SETUP_H
#define WIFI_SETUP_H
#endif
#include <html.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);


WiFiEventHandler WiFiConnectHandler;
WiFiEventHandler WiFiDisconnectHandler;


void onWiFiConnect(const WiFiEventStationModeGotIP& event){
	IPAddress t=WiFi.localIP();
	Serial.print("IP Address : ");
	Serial.println(t);
}
void onWiFiDisconnect(const WiFiEventStationModeDisconnected& event){
	Serial.println("Desconectou!!!!! ");
//	WiFi.disconnect();
//	WiFi.begin();
}
void conecttion(String ssid2,String pwd2){
	WiFiConnectHandler = WiFi.onStationModeGotIP(onWiFiConnect);
	//WiFiDisconnectHandler = WiFiEventStationModeDisconnected(onWiFiDisconnect);
	
  WiFiDisconnectHandler = WiFi.onStationModeDisconnected(onWiFiDisconnect);
   
	
	Serial.println(ssid2);Serial.println(pwd2);
	WiFi.disconnect();
	Serial.println("comecafggg");
	WiFi.begin(ssid2,pwd2);
}

void handleRoot() {
Serial.println("handleRoot");
  int z = server.args();
  if (z > 0) {
    String _pwd = server.arg(1);
    uint8_t SSID_INDEX = server.arg(0).toInt();
	conecttion(String(WiFi.SSID(SSID_INDEX)),_pwd);
// CALL conect
  }
  else {
    int scanResult = WiFi.scanNetworks();
    //String APfound = "";
    String APfound = "<option value='0'>" + WiFi.SSID() + "</option>\n";
    for (int8_t i = 0; i <= scanResult; i++) {
      String str2 = WiFi.SSID(i).c_str();
      APfound += "<option value='" + String(i) + "'>" + str2 + "</option>\n";
    }
    Serial.println (APfound);
    String APs1=APs;
    APs1.replace("opcoes", APfound);
    server.send(200, "text/html", APs1);
  }
}
void WiFi_init() {
Serial.println("WIFI INIT");
	byte mac[6];
  	WiFi.macAddress(mac);
	WiFi.begin();
	int i=0;
	while (!WiFi.connected()){
		i++;
		if(i>10){
		exit;
		}
	}
	String appoint ="";
  	Serial.print(mac[1],HEX);
  	Serial.println(mac[0],HEX);
  	appoint = "MERDA_"+ String(mac[1],HEX)+String(mac[0],HEX);
  	Serial.println(appoint);
  	WiFi.mode(WIFI_AP);
  	WiFi.softAP(appoint, "password");
  	delay(200);
  	
  	server.begin();
  	server.on("/", handleRoot);
}
void loop1() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  delay(300);
}


