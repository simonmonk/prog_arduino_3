#include <EEPROM.h>
const int maxPasswordSize = 20;
char password[maxPasswordSize];

void setup() {
  EEPROM_readAnything(0, password);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Your password is:");
  Serial.println(password);
  Serial.println("Enter a NEW password");     
  while (!Serial.available()) {};
  int n = Serial.readBytesUntil('\n', password, maxPasswordSize);
  password[n] = '\0';
  EEPROM_writeAnything(0, password); 
  Serial.print("Saved Password: ");
  Serial.println(password);
}

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
