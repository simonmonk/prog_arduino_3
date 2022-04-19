#include <EEPROM.h>

int addr = 0;
byte b;

void setup() {
  Serial.begin(9600);
  b = EEPROM.read(addr);
}

void loop() {
  if (Serial.available() > 0) {
    int i = Serial.parseInt();
    if (i <= 255) {
      b = lowByte(i);
      EEPROM.write(addr, b);
      Serial.println("saved byte");
    }
    else {
      Serial.println("number too big");
    }
  }
  Serial.println(b);
  delay(1000);
}
