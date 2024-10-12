#ifndef WIFIHANDLE_H
#define WIFIHANDLE_H
#endif
#include <ESP8266WiFi.h>
#include "definicao.h"

WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;
// Replace with your network credentials
extern  const String ssid ;
extern  const String password ;




void onWifiConnect(const WiFiEventStationModeGotIP& event) {
     IPAddress t = WiFi.localIP();
     Serial.print("IP address: ");
     Serial.print(WiFi.localIP());
     Serial.print("\tRRSI: ");
     Serial.println(WiFi.RSSI());
}

void onWifiDisconnect(const WiFiEventStationModeDisconnected& event) {
     Serial.println("Disconnected from Wi-Fi, trying to connect...");
     WiFi.disconnect();
     WiFi.begin(ssid, password);
}


void initWiFi() {
     wifiConnectHandler = WiFi.onStationModeGotIP(onWifiConnect);
     wifiDisconnectHandler = WiFi.onStationModeDisconnected(onWifiDisconnect);
     WiFi.mode(WIFI_STA);
     Serial.println("\nSSID:"+ssid+"\t\t PASSWORD:"+password);
     WiFi.begin(ssid, password);
}
