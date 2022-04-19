// 03_01_blink_function

const int ledPin = 13;
const int delayPeriod = 250;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 20; i ++) {
    flash();
  }
 delay(3000);
}

void flash() {
   digitalWrite(ledPin, HIGH);
   delay(delayPeriod);
   digitalWrite(ledPin, LOW);
   delay(delayPeriod);
}
