
unsigned long idx;
unsigned long pasted;
int strong;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  idx = 0;
  pasted = 0;
  strong = 0;
  
  SREG |= 0x80;  
  
  TCCR0A = 0x42;
  TCCR0B = 0x84;
  // 분주율 64
  TIMSK0 = 0x02;
  OCR0A = 249;
  // 경계선 250

  TCCR2A = 0x83;
  TCCR2B = 0x84;
  TIMSK2 = 0x02;
  OCR2A = 50;
}
ISR(TIMER0_COMPA_vect){
  idx++;
  // 1ms 단위로 증가  
}
ISR(TIMER2_COMPA_vect){  
  // 실행 될때마다 시작값을 다시 설정하여야 한다.
  
}
unsigned long myMillis(){
  return idx;
}

void loop() {
  // put your main code here, to run repeatedly:  
  if(pasted == 0){
    pasted = myMillis();
  }
  OCR2A = strong;
  
  while(myMillis() - pasted < 10){           
    
  }
  strong++;
  if(strong >= 255){
    strong = 0;
  }
  pasted = 0;
  
}
