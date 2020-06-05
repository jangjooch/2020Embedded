unsigned char led;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  led = 0x01;
  
  DDRB = 0x0F;
  DDRC = 0x0F;
  
  SREG |= 0x80;
  
  TCCR1A = 0x00;
  // OCnX 핀 차단
  // WGM1, 0  -> 0 0
  TCCR1B = 0x05;
  // WGM3, 2 -> 0 0 -> Normal 모드
  // SC2, 1, 0 -> 101 -> 분주율 1024
  TCCR1C = 0x00;
  // FOC1A, B, C -> 0 0 0
  TIMSK1 = 0x01;
  // OCIE1B OCIE1A TOIE1 -> 0 0 1 -> Overflow Enable
  TCNT1 = 49911;
  // TOP 설정

  
}
unsigned long startMilli = 0;
ISR(TIMER1_OVF_vect){
  TCNT1 = 49911;
  if(led == 0x80) led = 0x01;
  else led = led << 1;
  if(startMilli == 0){
    startMilli = millis();
  }
  else{
    Serial.println(millis() - startMilli);
    startMilli = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  PORTB = ~led;
  PORTC = ~(led >> 4);
}
