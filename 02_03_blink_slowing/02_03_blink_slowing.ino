// 02_03_blink_slowing

int ledPin = 13;
int delayPeriod = 100;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
 digitalWrite(ledPin, HIGH);
 delay(delayPeriod);
 digitalWrite(ledPin, LOW);
 delay(delayPeriod);
 delayPeriod = delayPeriod + 100;
 if (delayPeriod == 1000) {
  delayPeriod = 100;
 }
}
