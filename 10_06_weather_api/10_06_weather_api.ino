#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "";
const char* password = "";
const char* key = "";

const int ledPin = LED_BUILTIN;
const long fetchPeriod = 60000; // milliseconds
long lastFetchTime = 0;

void setup(void) {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  connectWiFi();
}

void loop(void) {
  long now = millis();
  if (now - lastFetchTime > fetchPeriod) {
    lastFetchTime += fetchPeriod;
    //int windspeed = fetchWindSpeed();
    //Serial.println(windspeed);
    //tone(ledPin, 0.5);
  }
  // windspeed: 0     50
  // ledPeriod: 1000  100
}

// http://api.weatherstack.com/current?access_key=8ca698469239c5b4127a5d54b57ef06b&query=London
// 

int fetchWindSpeed() {
  int speed = -1;
  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }
  HTTPClient client;
  client.begin("http://api.weatherstack.com/current?access_key=8ca698469239c5b4127a5d54b57ef06b&query=London");
  int responseCode = client.GET();
  if (responseCode == HTTP_CODE_OK) {
    String data = client.getString();
    // looking for "wind_speed": 0,
    //Serial.println(data);
    int numberStartIndex = data.indexOf("\"wind_speed\":");
    int numerEndIndex = data.indexOf(",", numberStartIndex);
    String speedText = data.substring(numberStartIndex + 13, numerEndIndex);
    Serial.println(speedText);
    speed = speedText.toInt();
  }
  //return speed;
  return 10;
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
}
