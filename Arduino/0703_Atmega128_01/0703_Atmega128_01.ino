
void setup() {
  // put your setup code here, to run once:
  DDRA = 0x01;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTA = 0x01;
  delay(1000);
  PORTA = 0x00;
  delay(1000);
}
