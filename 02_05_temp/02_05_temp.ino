// 02_05_temp

void setup() {
  Serial.begin(9600);
  int degC = 20;
  int degF;
  degF = degC * 9 / 5 + 32;
  Serial.println(degF); 
}

void loop(){}
