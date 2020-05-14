#include <TimerOne.h>

int count = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Timer1.initialize(1000000);
  // 1초마다
  Timer1.attachInterrupt(Counting);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void Counting(){
  count++;
  Serial.println(count);
}
