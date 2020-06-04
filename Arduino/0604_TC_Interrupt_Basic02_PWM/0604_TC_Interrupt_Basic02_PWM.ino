unsigned char led;
int idx;
unsigned long pasted = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  led = 0x01;
  idx = 0;
  SREG |= 0x80;
  // Global Interrupt Enable


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
  DDRB = 0x0F;
  DDRC = 0x0F;
}

ISR(TIMER2_COMPA_vect){  
  // 실행 될때마다 시작값을 다시 설정하여야 한다.
  
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTC = ~led;
  PORTB = ~(led >> 4);
  // OCR2A의 값에 따라 PWM이 결정되어 흡사
  // AnalogWrite되는 것과 비슷한 LED 모습을 확인할 수 있다.
  
  for(int i = 0 ; i < 256 ; i++){
    OCR2A = i;
    delay(10);
  }
  
  
}
