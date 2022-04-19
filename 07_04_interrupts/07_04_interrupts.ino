const int interruptPin = 2;
const int ledPin = 13;
int period = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin), goFast, FALLING);
}

void loop()  {
  digitalWrite(ledPin, HIGH);
  delay(period);
  digitalWrite(ledPin, LOW);
  delay(period);  
}

void goFast() {
  period = 100;
}
