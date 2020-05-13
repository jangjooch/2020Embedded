#include<Servo.h>

Servo test;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  test.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  int aValue = analogRead(0);
  Serial.println(aValue);
  int setAngle = map(aValue, 0, 1023, 0, 180);
  // 라이브러리를 통하여 입력을 하는 것이기에
  // duty cycle에 맞추어 하지 않고 0 ~ 180 도 라는
  // 범위에 따라 작동되도록 하는 것이다.
  test.write(setAngle);
  delay(100);
}
