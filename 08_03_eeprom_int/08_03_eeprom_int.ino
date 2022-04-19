#include <EEPROM.h>

int i;

void setup() {
  Serial.begin(9600);
  i = readEEPROMint(0);
}

void writeEEPROMint(int addr, int x) {
  EEPROM.write(addr, highByte(x));
  EEPROM.write(addr + 1, lowByte(x));
}

int readEEPROMint(int addr) {
  int high = EEPROM.read(addr);
  int low = EEPROM.read(addr + 1);
  return (high << 8) + low;
}

void loop() {
  if (Serial.available() > 0) {
    i = Serial.parseInt();
    writeEEPROMint(0, i);
    Serial.println("saved int");
  }
  Serial.println(i);
  delay(1000);
}
