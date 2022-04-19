#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>

const char* ssid = "my network name";
const char* password = "my password";
const char* hostname = "esp32";

const int touchPin = 13;

WebServer server(80);

void handleRoot() {
  String message = "<h1>Touch value: ";
  message += touchRead(touchPin);
  message += "</h1>";
  server.send(200, "text/html", message);
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
