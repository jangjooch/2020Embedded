#include <TimerOne.h>

int countDown = 0;

unsigned long startTime;
// HIGH 기록
unsigned long endTime;
// LOW 기록

void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT);  
  attachInterrupt(1, timeRecord, CHANGE);
  // input에 대한 interrupt 생성
  Timer1.initialize(1000);
  Timer1.attachInterrupt(getTime);
  // milli second 기록
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void timeRecord(){
  // mode CHANGE가 키 포인트이다.
  int state = digitalRead(3);
  if(state){
    startTime = countDown;
    // 처음 눌렀을 때 기록
  }
  else{
    endTime =countDown;
    // 마지막 때었을 때 기록
    Serial.println(endTime - startTime);
  }
}

void getTime(){
  countDown++;
  // 시간 기록
}
