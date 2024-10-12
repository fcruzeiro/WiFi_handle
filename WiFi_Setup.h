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
   
	
Serial.println(ssid2+"\t"+pwd2);
	WiFi.disconnect();
	Serial.println("comecafggg");
	WiFi.begin(ssid2,pwd2);
	delay(10000);
}

void handleRoot() {
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
   Serial.println ("APfound");
    String APs1=APs;
    APs1.replace("opcoes", APfound);
    server.send(200, "text/html", APs1);
  }
}
void WiFi_init() {
WiFi.mode(WIFI_STA);
	Serial.println("\nWIFI INIT");
	Serial.println(WiFi.SSID());
	WiFi.setAutoReconnect(true);
	WiFi.persistent(true);
  //	WiFi.mode(WIFI_STA);
	WiFi.begin();
	int i=0;
	while (!WiFi.isConnected()){
	Serial.print("#");
		i++;
		delay(1000);
	
		if(i>30){
			i=0;
			break;
		}
	}
	Serial.println("\nCONTINUOU");
      if(!WiFi.isConnected()){
      	byte mac[6];
  		WiFi.macAddress(mac);
		String appoint ="";
   		if(String(mac[1],HEX).length()<2) appoint="0"+String(mac[1],HEX);
        else appoint=String(mac[1],HEX);
        if(String(mac[0],HEX).length()<2) appoint=appoint+"0"+String(mac[0],HEX);
        else appoint=appoint+String(mac[0],HEX);
        appoint.toUpperCase();
  		appoint="MERDA_"+ appoint;
  		Serial.println("AP : "+appoint);
  		WiFi.mode(WIFI_AP);
  		WiFi.softAP(appoint, "password");
  		delay(2);
  	 }
     
  	server.begin();
  	server.on("/", handleRoot);

      }

void loop1() {
  // put your main code here, to run repeatedly:
  
  delay(300);
}


