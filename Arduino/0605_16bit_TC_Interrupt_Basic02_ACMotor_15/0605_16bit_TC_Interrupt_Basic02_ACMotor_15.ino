// 15번 모드
void setup() {
  // put your setup code here, to run once:
  DDRB = 0x0F;
  SREG |= 0x80;
  TCCR1A = 0x23;
  // COMB1 COMB0 : 1 0 -> ICR1을 만나면 Clear
  // WGM11 WGM10 : 1 0 -> 14번모드 1 1 1 0 을 위함
  TCCR1B = 0x1A;
  // WGM13 WGM12 : 1 1 -> 14번모드 1 1 1 0 을 위함
  // CS12 CS11 CS10 : 분주율 8 -> 0 1 0 을 위함
  TCCR1C = 0x00;
  // PWM 모드에서는 설정할 것이 없다.
  OCR1A = 40000;
  // TOP 설정
  // 분주 = 1/16 * 8 * 40000 = 20000nanoSec = 20ms

  // 진폭 설정
  // 1/16 * 8 * OCR1A = 진폭
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  OCR1B = 1000;
  // 1/16 * 8 * 1000 = 0.5ms 진폭 = 0도
  delay(1000);
  OCR1B = 3000;
  // 1/16 * 8 * 3000 = 1.5ms 진폭 = 90도
  delay(1000);
  OCR1B = 5000;
  // 1/16 * 8 * 5000 = 2.5ms 진폭 = 180도
  delay(1000);
}
