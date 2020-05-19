#include <TimerOne.h>

int count = 0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerISR);
  //attachInterrupt(0, externalISR, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void externalISR(){
  count ++;
  Serial.println(count);
  if(count%2 == 0){
    digitalWrite(13,LOW);
  }
  else{
    digitalWrite(13,HIGH);
  }
}

void timerISR(){
  count++;
  if(count%2 == 0){
    digitalWrite(13,LOW);
  }
  else{
    digitalWrite(13,HIGH);
  }
}
