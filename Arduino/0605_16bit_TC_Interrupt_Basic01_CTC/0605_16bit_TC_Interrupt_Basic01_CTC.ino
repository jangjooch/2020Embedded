unsigned char led;

void setup() {
  // put your setup code here, to run once:
  led = 0x01;
  
  DDRB = 0x0F;
  DDRC = 0x0F;
  SREG |= 0x80;
  
  TCCR1A = 0x00;
  // OCnX 핀 차단
  // WGM1, 0  -> 0 0
  TCCR1B = 0x0D;
  // WGM3, 2 -> 0 1 -> CTC 모드
  // SC2, 1, 0 -> 101 -> 분주율 1024
  TCCR1C = 0x00;
  // FOC1A, B, C -> 0 0 0
  TIMSK1 = 0x02;
  // OCIE1B OCIE1A TOIE1 -> 0 1 0 -> COMPA Enable
  OCR1A = 15625;
  // Bottom 설정
  
}
ISR(TIMER1_COMPA_vect){
  if(led == 0x01) led = 0x80;
  else led = led >> 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB = ~led;
  PORTC = ~(led >> 4);
}
