
volatile unsigned long idx = 0;

unsigned long tSet[2] = {0,0};
unsigned long pValue[2] = {0,0};
long angle[2] = {90, 90};

long mapping(long x,unsigned long in_min,unsigned long in_max,unsigned long out_min,unsigned long out_max);

long result = 0;

void setup() {
  // put your setup code here, to run once:
// 노말모드

  Serial.begin(9600);

  
  TCCR1B = 0x01;
  // 8분주율
  TIMSK = (1<<TOIE1);
  // TImer 1 Overflow Enable
  TCNT1 = -8000;
  // 시작값이 0에서 -2000 되것이기에 오버플로우로 인하여 65xxxx-2000이 된 것이다.
  // 1/16 * 8 * 2000 = 1000;
  // 16비트범위 : 0 ~ 65535

  // 1분주율 -8000 -> 1/16 * 1 * 8000 = 500;
  // 50 ~ 90. 중간 : 70
  
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
  EICRA = 0x05;
  // ISC31 ISC30 ISC21 ISC20 | ISC11 ISC10 ISC01 ISC00
  // INT 3, 2, 1, 0
  // Change 설정
  //EICRB = 0x01;
  // INT 4
  // Change 설정 Change -> 0 1
  EIMSK = 0x03;
  // INT 4, 3, 2, 1, 0 Enable
  
  SREG |= 0x80;
  DDRB = 0x08;
}

void loop() {
    Serial.print(pValue[0]);
    Serial.print(" ");
    Serial.print(angle[0]);
    Serial.print(" ");
    Serial.print(pValue[1]);
    Serial.print(" ");
    Serial.println(angle[1]);
    
    
    for(int i = 0 ; i < 2 ; i++){
      if(angle[i] > 180){
        angle[i] = 180;
      }
      if(angle[i] < 0){
        angle[i] = 0;
      }
      PORTB = (1<<i);
      OCR3A = mapping(angle[i], 50, 90, 1000, 5000);
      
      delay(10000);
    }
    //OCR3A = mapping(pValue, 50, 90, 1000, 5000);
    //delay(1000);
}
ISR(TIMER1_OVF_vect){
  
  TCNT1 = -8000;
  idx  = idx + 1;
}


ISR(INT0_vect){
  if( (PIND & 0x01) == 0x01 ){
    tSet[0] = idx;
    //PORTC = 0x80;
  }
  else{
    //PORTC = 0x00;
    if(tSet[0] != 0){
      pValue[0] = idx - tSet[0];
      if(pValue[0] > 80){
        angle[0] = angle[0]+1;
      }
      if(pValue[0] < 60){
        angle[0] = angle[0] - 1;
      }
    }
  }
}

ISR(INT1_vect){
  if( (PIND & 0x02) == 0x02 ){
    tSet[1] = idx;
  }
  else{
    if(tSet[1] != 0){
      pValue[1] = idx - tSet[1];
      if(pValue[1] > 80){
        angle[1] = angle[1]+1;
      }
      if(pValue[1] < 60){
        angle[1] = angle[1] - 1;
      }
    }
  }
}

long mapping(long x,unsigned long in_min,unsigned long in_max,unsigned long out_min,unsigned long out_max)
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
