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
int sensor1 = 0;
int sensor2 = 0;
int sensor3 = 0;
int sensor4 = 0;

void setup() {

  DDRD = 0xFF;
  DDRC = 0xF0;

  
  SREG |= 0x80;
  // Interrupt Enable

  TCCR1A = 0x00;
  // OCN 출력 안하니까 Block
  // COM1A1 COM1A0 - - - - - - WGM11 WGM10
  // Normal 모드
  TCCR1B = 0x03;
  // 0 0 1 1
  // 분주율 64
  // ICES1
  // 0이면 하강엣지
  // 1이면 상승엣지
  // 엣지에 대한 결과는 OC1A에 들어오는 결과를 통해
  // Interrupt를 발생시킨다.
  // 결과는 ICR1에 전달
  // 분주율 64
  TCCR1C = 0x00;
  // OC1 출력 X
  TIMSK1 = 0x21;
  // ICIE1
  // 입력캡처 Interrupt Enable
  // OVF 인터럽트 Enable
  TCNT1 = 100;
  // TOP 100
  //TIFR = 0x20;  


  DDRB = 0xFE;
  // echo는 읽고 trigger는 출력한다.
  
  Serial.begin(9600);
}

ISR(TIMER1_CAPT_vect){
  Serial.println("CAPT");
  captFlag =1;
  Serial.println(ICR1);  
}

int idx = 0;

ISR(TIMER1_OVF_vect){
  idx++;
  switch(idx){
    case 1:
        FND_ComSel(0); 
        Disp_FND(~fnd_data[sensor4]); 
        break;
    case 2:        
        FND_ComSel(1); 
        Disp_FND(~fnd_data[sensor3]); 
        break;
    case 3:
        FND_ComSel(2); 
        Disp_FND(~fnd_data[sensor2]);     
        break;
    case 4:
        FND_ComSel(3); 
        Disp_FND(~fnd_data[sensor1]);     
        break;
    default:
        idx = 0;
  }  
}

int state = 0;

void loop() {
  // put your main code here, to run repeatedly:   

  unsigned long sensor = 0;
  if(state == 0){
    PORTB = 0x00;
    delayMicroseconds(1);
    PORTB = 0x02;
    delayMicroseconds(11);
    // 입력을 10micro sec 이상 주어야 한다.
    PORTB = 0x00;
    delayMicroseconds(1);
    TCNT1 = 100;
    state = 1;
    
  }  
  if(captFlag){
    // capture interrupt 발생하였을 때
    double value = ICR1 * (0.000002) * 4 * 377 * 100;
    // ICR1의 값은 Interrupt가 발생하였을 때의
    // TCNT1의 값이다. 즉 얼마나 시간이 걸렸는지
    // 대략적으로 확인이 가능하다는 것이다.
    Serial.println(ICR1);
    Serial.println(value);
    int sen10 = (int)value;
    int sen1 = (value - sen10) * 100;
    
    sensor1 = sen10 / 10;
    sensor2 = sen10 % 10;
    sensor3 = sen1 / 10;
    sensor4 = sen1 % 10;
    state = 0;
  }
  
  delayMicroseconds(30);  
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
