void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
}

void loop() {
  int aValue = analogRead(0);
  int cycle = map(aValue, 0, 1023, 0, 1000);
  digitalWrite(3, HIGH);
  delay(1);
  delayMicroseconds(cycle);
  
  digitalWrite(3, LOW);  
  delay(18);
  delayMicroseconds(1000-cycle);
}
