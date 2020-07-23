
// 1 개의 Reicever 값에 대한 결과는 확인됨.
// 이유는 모르겠으나 아마도 코드 수행에 따른 결과에 의하여
// OCR3A 값이 기존의 1000 ~ 5000이 아닌 
// 18000 ~ 36000 이 되었다.

unsigned long idx = 0;
unsigned char test = 0;

// Receiver를 통해 받는 값 저장용
unsigned long timer[5] = {0, 0, 0, 0, 0};
unsigned long pwm_value[5] = {0, 0, 0, 0, 0};

char flag00 = 0;
char flag01 = 0;
char flag02 = 0;
char flag03 = 0;
char flag04 = 0;

void setup() {
  // put your setup code here, to run once:
  UCSR0A = 0x00;
  UCSR0B = 0x18;
  UCSR0C = 0x06;
  UBRR0H = 0;
  UBRR0L = 103;
  
  // Motor 제어 Duty Cycle 생성 16bit timer
  TCCR3A = 0x82;
  // COMA1 COMA0 : 1 0 -> ICR1을 만나면 Clear
  // WGM11 WGM10 : 1 0 -> 14번모드 1 1 1 0 을 위함
  TCCR3B = 0x1A;
  // WGM13 WGM12 : 1 1 -> 14번모드 1 1 1 0 을 위함
  // CS12 CS11 CS10 : 분주율 8 -> 0 1 0 을 위함
  TCCR3C = 0x00;
  // PWM모드에서는 출력할 것이 없다.
  ICR3 = 40000;
  // TOP 설정
  // 분주 = 1/16 * 8 * 40000 = 20000nanoSec = 20ms
  // Duty Cycle 설정
  DDRE = 0x0F;
  // OC3A 출력  -> PE3
  // INT 4 입력 -> PE4
  
  // pwm 입력측정을 위한 외부 Interrupt
  EICRA = 0x55;
  // ISC31 ISC30 ISC21 ISC20 | ISC11 ISC10 ISC01 ISC00
  // INT 3, 2, 1, 0
  // Change 설정
  EICRB = 0x01;
  // INT 4
  // Change 설정 Change -> 0 1
  EIMSK = 0b00011111;
  // INT 4, 3, 2, 1, 0 Enable
  
  SREG |= 0x80;
  
  DDRF = 0x01;
  PORTF = 0x00;
  OCR3A = 1000;

  DDRB = 0x03;
  PORTB = 0x03;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  UART_Putchar(pwm_value[0] >> 8);
  UART_Putchar(pwm_value[0]);
  long result = 1500 - pwm_value[0];
  if(result < 0){
    result = -result;
    PORTB = 0x01;
  }
  else{
    PORTB = 0x03;




    
  }
  if(result < 100){
    result = 0;
  }  
  OCR3A = map(result, 0, 400, 18000, 36000);
  //OCR3A = 30000;
  delay(500);
}

// PD0
ISR(INT0_vect){
  if( (PIND & 0x01) == 0x01 ){
    timer[0] = micros();
    PORTF = 0x01;
  }
  else{
    if(timer[0] != 0){
      PORTF = 0x00;
      pwm_value[0] = micros() - timer[0];
      flag00 = 1;
    }
  }
}
// PD1
ISR(INT1_vect){
  if((PIND & (1 << 1))){
    timer[1] = idx;
  }
  else{
    if(timer[1] != 0){
      pwm_value[1] = idx - timer[1];
      flag01 = 1;
    }
  }
}
// PD2
ISR(INT2_vect){
  if((PIND & (1 << 2))){
    timer[0] = idx;
    test = 5;
  }
  else{
    if(timer[2] != 0){
      pwm_value[2] = idx - timer[2];
      flag02 = 1;
    }
  }
}
// PD3
ISR(INT3_vect){
  if((PIND & (1 << 3))){
    timer[3] = idx;
  }
  else{
    if(timer[3] != 0){
      pwm_value[3] = idx - timer[3];
      flag03 = 1;
    }
  }
}
// PE4
ISR(INT4_vect){
  if((PINE & (1 << 4))){
    timer[4] = idx;
  }
  else{
    if(timer[4] != 0){
      pwm_value[4] = idx - timer[4];
      flag04 = 1;
    }
  }
}

void UART_Putchar(unsigned char data){
  while((UCSR0A & 0x20) == 0x0){
    // UDRE0 이 1이 될때가지 대기
    // 즉 데이터 전송 버퍼가 비일때까지 대기
    // 전송버퍼가 비인다면 1로 Set 됨
    ;
  }
  UDR0 = data;
  //데이터 씀
}
