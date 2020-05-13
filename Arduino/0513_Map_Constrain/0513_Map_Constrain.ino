void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valueA = analogRead(0);
  Serial.println(valueA);
  int adcValue = map(valueA, 0, 1023, 0, 255);
  adcValue = constrain(adcValue, 0, 255);
  analogWrite(11, adcValue);
  //delay(1000);
}
