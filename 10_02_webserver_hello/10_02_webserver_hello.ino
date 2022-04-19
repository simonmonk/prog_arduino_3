#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>

// Change these 2 for your network!
//const char* ssid = "my network name";
//const char* password = "my password";
const char* ssid = "Monk";
const char* password = "d4daaa7eda";
const char* hostname = "esp32";

WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>Hello World!</h1>  ");
}

void setup(void) {
  Serial.begin(9600);
  connectWiFi();
  if (MDNS.begin(hostname)) {
    Serial.println("Webserver started");
  }
  server.on("/", handleRoot);
  server.begin();
  Serial.print("Open your browser on http://"); Serial.println(WiFi.localIP());
  Serial.print("this may also work: http://"); Serial.print(hostname); Serial.println(".local");
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
}

void loop(void) {
  server.handleClient();
  delay(2);
}
