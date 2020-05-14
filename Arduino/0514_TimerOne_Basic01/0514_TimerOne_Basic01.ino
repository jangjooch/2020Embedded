#include <TimerOne.h>

int ledState = LOW;
volatile unsigned long bCount = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  Timer1.initialize(150000);
  Timer1.attachInterrupt(LedChange);
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long bCopy;
  noInterrupts();
  bCopy = bCount;
  interrupts();

  Serial.print("bCount : ");
  Serial.println(bCopy);
  delay(100);
}

void LedChange(){
  if(ledState){
    ledState = LOW;
  }
  else{
    ledState = HIGH;
    bCount++;
  }
  digitalWrite(2, ledState);
}
