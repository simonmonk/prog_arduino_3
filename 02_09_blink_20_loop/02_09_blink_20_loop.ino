// 02_09_blink_20_loop

int ledPin = 13;
int delayPeriod = 100;
int count = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
 digitalWrite(ledPin, HIGH);
 delay(delayPeriod);
 digitalWrite(ledPin, LOW);
 delay(delayPeriod);
 count ++;
 if (count == 20) {
   count = 0;
   delay(3000);
 }
}
