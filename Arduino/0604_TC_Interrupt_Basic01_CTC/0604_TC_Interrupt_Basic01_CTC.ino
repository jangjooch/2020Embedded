
unsigned char led;
unsigned char idx;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  led = 0x01;
  idx = 0x01;
  
  SREG |= 0x80;
  // Global Interrupt Enable
  
  TCCR1A = 0x02;
  TCCR1B = 0x05;
  // CTC 모드
  // 분주율 1 1 1 1024설정
  // 0 0 0 0 1 1 1 1
  // 0 0 MG13 MG12
  
  TIMSK1 = 0x02;
  // CTC EnAble
  OCR1AH = 0xFF;  
  OCR1AL = 0x0F;
  // 시작값 설정
}

// TIMER0_OVF_vect
// -> 아두이노 라이브러리에서 이미 사용중이라고 안됨
// TIMER1_OVF_vect -> 이건 가능
// TIMER0_COMPA_vect ->이건 가능

ISR(TIMER1_COMPA_vect){  
  // 실행 될때마다 시작값을 다시 설정하여야 한다.
  idx++;
  led = led << 1;
  Serial.println("AC");  
  if(idx == 100){
    
    idx = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:  
}
