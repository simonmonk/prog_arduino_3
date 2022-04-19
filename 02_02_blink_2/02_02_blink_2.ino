// 02_02_blink_2

int ledPin = 13;
int delayPeriod = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
 digitalWrite(ledPin, HIGH);
 delay(delayPeriod);
 digitalWrite(ledPin, LOW);
 delay(delayPeriod);
}
