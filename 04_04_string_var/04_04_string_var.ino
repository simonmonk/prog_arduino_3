char message[] = "Hello";

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(message);
  delay(1000);
}
