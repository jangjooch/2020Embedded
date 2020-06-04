
int idx;
unsigned long pasted = 0;
int strong;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  idx = 0;
  strong = 0;
  SREG |= 0x80;
  // Global Interrupt Enable
  DDRB = 0x08;

  TCCR2A = 0x83;  
  // COM2A1 COM2A0 COM2B1 COM2B0 - - WGM21 WGM20
  // COM2A1 COM2A0  1  0
  // OCR2A 이상일때 LOW 이하일때 HIGH
  // COM2A1 COM2A0  1  1
  // OCR2A 이상일때 HIGH 이하일때 LOW

  // WGM22 WGM21 WGM20
  //    0    1     1
  // FAST PWM 설정
  TCCR2B = 0x84;  
  // FOC2A FOC2B - - WGM22 CS02 CS01 CS00
  // FPC2A 접근 허가
  // 분주율 1 0 0 64설정
  // 분주율은 듀티사이클의 %를 변화시킬 수 있다.
  TIMSK2 = 0x02;
  // OCIE2A EnAble
  OCR2A = 50;
  // LOW HIGH 기준 설정

  TCCR0A = 0x42;
  // 결과값 토글 및 CTC 설정
  TCCR0B = 0x84;
  // FOC0A 접근 허용
  // 분주율 64
  TIMSK0 = 0x02;
  // CTCA 사용한다는 마스크
  OCR0A = 249;
  // 경계선 250
}
ISR(TIMER0_COMPA_vect){
  idx++;
  //Serial.println(idx);
  // 1ms 단위로 증가  
}
ISR(TIMER2_COMPA_vect){  
  
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
  
  while(myMillis() - pasted > 10){     
    // delay처럼 작동
  }
  strong++;
  if(strong >= 255){
    strong = 0;
  }
  pasted = 0;
  //Serial.println(strong);
}
