#include <TimerOne.h>

int buttonState = LOW;
int countDown = 0;
unsigned long startTime;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);  
  //currTime = millis();
  attachInterrupt(0, timeRecord, CHANGE);
  // input에 대한 interrupt 생성
  Timer1.initialize(1000);
  Timer1.attachInterrupt(getTime);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void timeRecord(){
  int state = digitalRead(2);
  if(state){
    startTime = millis();
  }
  else{
    Serial.println(millis() - startTime);
  }
}
void getTime(){
  countDown++;  
}
