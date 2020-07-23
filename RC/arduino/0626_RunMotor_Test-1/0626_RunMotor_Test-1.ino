int output = 3;
int duty = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(output, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(output, 63); // 25%
  delay(1500);
  analogWrite(output, 127); // 50%
  delay(1500);
  analogWrite(output, 191); // 75%
  delay(1500);
  analogWrite(output, 255); // 100%
  delay(1500);
}
