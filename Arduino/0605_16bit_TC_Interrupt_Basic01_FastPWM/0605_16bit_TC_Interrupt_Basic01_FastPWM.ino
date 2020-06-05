unsigned char led;

void setup() {
  // put your setup code here, to run once:
  led = 0x01;
  
  DDRB = 0x0F;
  DDRC = 0x0F;
  SREG |= 0x80;
  
  TCCR1A = 0xC3;
  // 0 1 -> 특정 조건에서 Toggle
  // 1 0 -> OC1A 만날시 클리어
  // 1 1 -> OC1A 만날시 셋
  // WGM1, 0  -> 1 1
  TCCR1B = 0x04;
  // WGM3, 2 -> 0 1 -> FastPWM 모드
  // 0x0C;
  // 0 1 1 1 Fast PWM 10bit
  // SC2, 1, 0 -> 1 0 0 -> 분주율 256
  // 만약 0x04로 한다면 0 0 1 1 로서
  // PC PWM 모들 설정되어 진폭이 2배가 된다.
  TCCR1C = 0x80;
  // FOC1A, B, C -> 1 0 0
  // OC1A 출력 Enable
  TIMSK1 = 0x02;
  // OCIE1B OCIE1A TOIE1 -> 0 1 0 -> COMPA Enable
  OCR1A = 0x00F0;
  // Fast PWM 10bit이므로 OCR1A의 최댓값은 0x3FF이다
  // 이를 넘길경우 값이 나오지 않는다.
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
