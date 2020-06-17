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

void setup() {
  // put your setup code here, to run once:
  DDRD = 0xFF;
  DDRC = 0x0F;
  DDRB = 0x0F;
  
  SREG |= 0x80;
  // Interrupt Enable

  TCCR2A = 0x42;
  // 4 : Set 될 시 CTC ON
  // 2 : CTC모드
  TCCR2B = 0x84;
  // CTC 모드 설정
  // 분주율 64
   TIMSK2 = 0x02;
  // OCIE2A EnAble
  OCR2A = 249;
  // 상한 값 출력  
}

void loop() {
  // put your main code here, to run repeatedly:  
  for(count = 0; count < 10000; count++){
  int num1000 = count / 1000;      // 1000의 자리 숫자 계산
  int num100 = (count % 1000) / 100; // 100의 자리 숫자 계산
  int num10 = (count % 100) / 10;    // 10의 자리 숫자 계산
  int num1 = count % 10;               // 1의 자리 숫자 계산
  
  // 1000자리 숫자 출력 함수 호출
  FND_ComSel(0); 
  Disp_FND(~fnd_data[num1000]); 
  delay(5); // 5ms 시간 지연
  
  // 100자리 숫자 출력 함수 호출
  FND_ComSel(1); 
  Disp_FND(~fnd_data[num100]); 
  delay(5); // 5ms 시간 지연
  
  // 10자리 숫자 출력 함수 호출
  FND_ComSel(2); 
  Disp_FND(~fnd_data[num10]); 
  delay(5); // 5ms 시간 지연
  
  // 1자리 숫자 출력 함수 호출
  FND_ComSel(3); 
  Disp_FND(~fnd_data[num1]); 
  delay(5); // 5ms 시간 지연
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
  int i;
  char mask;
  // 0 1 2 3 4 5 6 7 
  //PORTD = fnd >> 2 ; // 2 3 4 5 6 7
  //PORTB = fnd >> 7; // 8
  
  //PORTD = ~(fnd << 2);
  //PORTB = ~(fnd >> 7);
  PORTD = ~(fnd << 1);
  for(i=0; i<7; i++){ // Bit0 ~ Bit6까지
    mask = 1 << i; // 각 자리수 별 bit mask 생성
    if(fnd & mask){      
      //digitalWrite(fnd_a + i, LOW);      
    }
    else {
      //digitalWrite(fnd_a + i, HIGH);
    }
  }  
}

unsigned long idx = 0;

ISR(TIMER2_COMPA_vect){
  idx++;
}

unsigned long MyMillis(){
  return idx;
}

void MyDelay(int a){
  unsigned long delayMilli = MyMillis();
  while(MyMillis() - delayMilli < a){
    //delay
  }
}
