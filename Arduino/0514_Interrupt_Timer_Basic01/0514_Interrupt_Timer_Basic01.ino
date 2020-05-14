#include <TimerOne.h>

int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  Serial.begin(9600);

  Timer1.initialize(10000);
  // 10ms 단위로 Timer Interrupt를 실행하도록 설정한다.
  Timer1.attachInterrupt(timerMethod);
  // Timer Interrupt이 실행될 함수를 지정하고
  // Interrupt을 생성한다.
}

void loop() {
  // put your main code here, to run repeatedly:

}

void timerMethod(){
  
  count++;
  if(count%100 == 0){
    digitalWrite(2, digitalRead(2)^1);
    // XOR 연산을 통해 HIGH와 LOW를 번갈아가며 출력할 수 있도록 한다.
    Serial.println(count);
  }
}
