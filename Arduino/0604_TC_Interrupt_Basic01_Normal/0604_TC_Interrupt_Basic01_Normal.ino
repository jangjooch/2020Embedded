#define _DISABLE_ARDUINO_TIMER0_INTERRUPT_HANDLER_

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
  // Timer1은 16비트카운터이기에 매우 느리다.
  // 약 4초마다 한번씩 실행된다.
  TCCR1A = 0x00;
  // WGM11 WGM10
  TCCR1B = 0x05;
  // WGM12 CS02 CS01 CS00
  // Normal 모드
  // 분주율 1 0 1 1024설정
  
  TIMSK1 = 0x01;
  // 오버 플로우 EnAble
  TCNT1 = 0x0000;
  // 시작값 설정
}

// TIMER0_OVF_vect
// -> 아두이노 라이브러리에서 이미 사용중이라고 안됨
// -> 그래서 위처럼 해제를 시켜야함
// TIMER1_OVF_vect -> 이건 가능
// TIMER0_COMPA_vect ->이건 가능

ISR(TIMER1_OVF_vect){
  TCNT0 = 0x0000;
  // 실행 될때마다 시작값을 다시 설정하여야 한다.
  idx++;
  led = led << 1;
  Serial.print(led); 
  Serial.println("AC");
  if(idx == 100){
    
    idx = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:  
}
