void setup() {
  Serial.begin(9600);
  Serial.println(__DATE__);
  Serial.println(__TIME__);
  Serial.println(F_CPU);
  Serial.println(ARDUINO);
}

void loop() {}
