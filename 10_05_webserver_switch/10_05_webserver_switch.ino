#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "index.h"

const char* ssid = "my network name";
const char* password = "my password";
const char* hostname = "esp32";

const int ledPin = LED_BUILTIN;

WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", index_template);
}

void handleSwitch() {
  String stateStr = server.arg(0);
  Serial.println(stateStr);
  if (stateStr == "1") {
    digitalWrite(ledPin, LOW);
  }
  else if (stateStr == "0") {
    digitalWrite(ledPin, HIGH);
  }
  server.send(200, "text/plain", "");
}

void setup(void) {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  connectWiFi();
  if (MDNS.begin(hostname)) {
    Serial.println("webserver started");
  }
  server.on("/", handleRoot);
  server.on("/switch", handleSwitch);
  server.begin();
  Serial.print("Open your browser on http://");
  Serial.println(WiFi.localIP());
  
}

void connectWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nConnected to: ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("this may also work: http://"); 
  Serial.print(hostname); Serial.println(".local");
}

void loop(void) {
  server.handleClient();
  delay(2);
}
