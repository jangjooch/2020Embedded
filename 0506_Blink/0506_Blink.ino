int i;
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  digitalWrite(13, LOW);
  Serial.write(i);
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(13, HIGH);
  Serial.write("test");
  Serial.write('\n');
  delay(1000);
}
