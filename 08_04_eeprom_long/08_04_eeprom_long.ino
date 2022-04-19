#include <EEPROM.h>


long x = 12345678;
long y = 0;

void setup() {
  Serial.begin(9600);
  EEPROM_writeAnything(0, x);
  Serial.print("wrote x: ");
  Serial.println(x);
  int n = EEPROM_readAnything(0, y);
  Serial.print("read y: ");
  Serial.println(y);
  Serial.println(n);
}

void loop() {}

template <class T> int EEPROM_writeAnything(int ee, const T& value) {
  const byte* p = (const byte*)(const void*)&value;
  int i;
  for (i = 0; i < sizeof(value); i++) {
    EEPROM.write(ee++, *p++);
  }
  return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value) {
    byte* p = (byte*)(void*)&value;
    int i;
    for (i = 0; i < sizeof(value); i++) {
      *p++ = EEPROM.read(ee++);
    }
    return i;
}
