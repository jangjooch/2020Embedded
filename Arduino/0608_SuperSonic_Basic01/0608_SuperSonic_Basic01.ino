int fnd_a = 1;
int fnd_b = 2;
int fnd_c = 3;
int fnd_d = 4;
int fnd_e = 5;
int fnd_f = 6;
int fnd_g = 7;

//int com1 = a0;
//int com2 = a1;
//int com3 = a2;
//int com4 = a3;
char num;

int count;

char fnd_data[10] = 
{0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92,
  0x82, 0xF8, 0x80, 0x90};
    
char captFlag = 0;
  
void setup() {

  DDRD = 0xFF;
  DDRC = 0xF0;
  DDRB = 0b11111110;;
  // echo와 trigger될 대상만 input으로 받는다.
  
  SREG |= 0x80;
  // Interrupt Enable

  TCCR0A = 0x42;
  // 4 : Set 될 시 CTC ON
  // 2 : CTC모드
  TCCR0B = 0x84;
  // CTC 모드 설정
  // 분주율 64
  TIMSK0 = 0x02;
  // OCIE2A EnAble
  OCR0A = 249;
  // 상한 값 출력


  TCCR1A = 0x00;
  // OCN 출력 안하니까 Block
  // COM1A1 COM1A0 - - - - - - WGM11 WGM10
  // Normal 모드
  TCCR1B = 0x03;
  // 1 0 1 1
  // 분주율 64
  // ICES1
  // 0이면 하강엣지
  // 1이면 상승엣지
  // 결과는 ICR1에 전달
  // 분주율 64
  TCCR1C = 0x00;
  // OC1 출력 X
  TIMSK1 = 0x20;
  // ICIE1
  // 입력캡처 Interrupt Enable
  // OVF 인터럽트 Enable
  TCNT1 = 100;
  // TOP 100
  //TIFR = 0x20;  
  
  PORTB |= 0x02;

  
  Serial.begin(9600);
}

unsigned long comMilli = 0;
unsigned long value = 0;

int state = 0;

ISR(TIMER1_CAPT_vect){
  Serial.println("CAPT");
  captFlag =1;
  Serial.println(ICR1);
  //delay(1);
}

void loop() {
  // put your main code here, to run repeatedly:   

  unsigned long sensor = 0;
  
  if(captFlag){
    double value = ICR1 * (1/1000000) * 4 * 377 * 100;
    captFlag = 0;
    Serial.println(ICR1);
    Serial.println(value);
  }
  
  
  
  if(comMilli > 15){
    FND_ComSel(0); 
    Disp_FND(~fnd_data[sensor]); 
  }
  else if(comMilli > 10){
    FND_ComSel(1); 
    Disp_FND(~fnd_data[sensor]); 
  }
  else if(comMilli > 5){
    FND_ComSel(2); 
    Disp_FND(~fnd_data[sensor]);     
  }
  else{
    FND_ComSel(3); 
    Disp_FND(~fnd_data[sensor]);     
  }
}

void FND_ComSel(char com)
{
  if(com == 0){ // 1000의 자리 숫자 공통 단자 HIGH
    PORTC = 0x01;    
  }
  else if(com == 1){ // 100의 자리 숫자 공통 단자 HIGH
    PORTC = 0x02;
  }
  else if(com == 2){ // 10의 자리 숫자 공통 단자 HIGH
    PORTC = 0x04;
  }
  else if(com == 3){ // 1의 자리 숫자 공통 단자 HIGH
    PORTC = 0x08;
  }
}
void Disp_FND(char fnd)
{  
  PORTD = ~(fnd << 1);  
}

unsigned long idx = 0;
unsigned long mil = 0;

ISR(TIMER0_COMPA_vect){
  
  idx++;
  mil++;
  comMilli++;
  if(idx > 1000)  {    
    idx = 0;
    Serial.println("loop");
  }
  if(comMilli>20){
    comMilli = 0;
  }
}

unsigned long MyMillis(){
  return mil;
}

void MyDelay(int a){
  unsigned long delayMilli = MyMillis();
  while((MyMillis() - delayMilli) <= a){
    //Serial.println(MyMillis() - delayMilli);
  }
}
