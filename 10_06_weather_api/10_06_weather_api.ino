#include <WiFi.h>
#include <HTTPClient.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const char* ssid = "MONKMAKES_GUEST";
const char* password = "6KeCt4cu9YfY";
const char* url = "http://api.openweathermap.org/data/2.5/weather?lat=53.925854&lon=-3.021994&appid=ea751fc7712f27059e8a99448213b712";

const long fetchPeriod = 60000L; // milliseconds 
long lastFetchTime = 0;

Adafruit_SSD1306 display(128, 64, &Wire, -1); 

int tempC = 0;
String placeText = String("Looking up..");

void setup(void) {
  Wire.begin(17, 16); // SDA, SCL         
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);  // may need to change this I2C address
  display.setTextColor(WHITE);
  display.setTextSize(1);
  Serial.begin(9600);
  connectWiFi();
  getWeatherData();
  updateDisplay();
}

void loop(void) {
  long now = millis();
  if (now - lastFetchTime > fetchPeriod) {
    lastFetchTime += fetchPeriod;
    getWeatherData();
    updateDisplay();
  }
}

void getWeatherData() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }
  HTTPClient client;
  client.begin(url);
  int responseCode = client.GET();
  if (responseCode == HTTP_CODE_OK) {
    String data = client.getString();
    String tempText = extractValue(data, "\"temp\":", false);
    tempC = tempText.toInt() - 273;
    placeText = extractValue(data, "\"name\":", true);
    //Serial.println(data);
  }
}

String extractValue(String data, char* key, boolean isString) {
  int valueStartIndex = data.indexOf(key);
  int n = strlen(key);
  String value = "";
  if (valueStartIndex > -1) {
    valueStartIndex += n;
    int valueEndIndex = data.indexOf(",", valueStartIndex);
    if (isString) {
      valueStartIndex ++;
      valueEndIndex --;
    }
    value = data.substring(valueStartIndex, valueEndIndex);
    Serial.println(value);
    return value;
  }
  return String("");
}

void updateDisplay() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(6);
  display.print(tempC);
  display.setTextSize(2);
  display.print("C");
  display.setCursor(0, 54);
  display.setTextSize(1);
  display.println(placeText);
  display.display();
}

void connectWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  display.clearDisplay();
  display.println("Connecting..");
  display.display();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    display.print(".");
    display.display();
  }
  display.clearDisplay();
  display.println("Connected to");
  display.println(ssid);
  display.display();
}
