volatile unsigned long idx = 0;
unsigned long timerSet = 0;
unsigned long pwmValue = 0;

unsigned long tSet = 0;
unsigned long pValue = 0;

long mapping(unsigned long x,unsigned long in_min,unsigned long in_max,unsigned long out_min,unsigned long out_max);

long result = 0;

void setup() {
  // put your setup code here, to run once:
// 노말모드

  Serial.begin(9600);

  
  TCCR1B = 0x02;
  // 8분주율
  TIMSK = (1<<TOIE1);
  // TImer 1 Overflow Enable
  TCNT1 = -20000;
  // 시작값이 0에서 -2000 되것이기에 오버플로우로 인하여 65xxxx-2000이 된 것이다.
  // 1/16 * 8 * 2000 = 1000;
  
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
  DDRC = 0x80;
  
  // pwm 입력측정을 위한 외부 Interrupt
  EICRA = 0x01;
  // ISC31 ISC30 ISC21 ISC20 | ISC11 ISC10 ISC01 ISC00
  // INT 3, 2, 1, 0
  // Change 설정
  //EICRB = 0x01;
  // INT 4
  // Change 설정 Change -> 0 1
  EIMSK = 0x01;
  // INT 4, 3, 2, 1, 0 Enable
  
  SREG |= 0x80;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // pwmValue = 80 ~ 960. middle = 492
    if(pwmValue > 40000000){
      // 값이 튀는거 잡아주는 역할
    }
    else{
      result = 490 - pwmValue;
    }
    if(result < 0){
      result = -result;
    }
    if(result < 100){
      result = 0;
    }

    // pValue = 7 ~ 14. middle = 10,11
    // 상 : 7,8
    // 하 : 13, 14
    // micros의 단위가 형성되지 않음
    
    Serial.println(pValue);
    //Serial.println(pValue);
    OCR3A = mapping(result, 0, 410, 1000, 5000);
    delay(1000);
}
ISR(TIMER1_OVF_vect){
  
  TCNT1 = -20000;
  idx  = idx + 1;
}


ISR(INT0_vect){
  if( (PIND & 0x01) == 0x01 ){
    timerSet = micros();
    tSet = idx;
    PORTC = 0x80;
  }
  else{
    PORTC = 0x00;
    if(timerSet != 0){
      PORTF = 0x00;
      pwmValue = micros() - timerSet;
      pValue = idx - tSet;
    }
  }
}

long mapping(unsigned long x,unsigned long in_min,unsigned long in_max,unsigned long out_min,unsigned long out_max)
{
  if(x > in_max){
    x = in_max;
  }
  else if(x < in_min){
    x = in_min;
  }
  unsigned long result = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return result;
}
