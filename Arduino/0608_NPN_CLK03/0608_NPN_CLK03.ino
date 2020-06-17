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
int min10;
int min1;
int sec10;
int sec1;

char fnd_data[10] = 
{0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92,
  0x82, 0xF8, 0x80, 0x90}; 

char sec1Clk = 0;
int sec1Num = 0;
char sec1Trigger = 0;

char sec10Clk = 0;
int sec10Num = 0;
char sec10Trigger = 0;

char min1Clk = 0;
int min1Num = 0;
char min1Trigger = 0;

char min10Clk = 0;
int min10Num = 0;
char min10Trigger = 0;

void setup() {
  // put your setup code here, to run once:
  count = 0;
  min10 = 0;
  min1 = 0;
  sec10 = 0;
  sec1 = 0;
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
  sec1Clk = 0;
  sec1Num = 0;
  sec1Trigger = 0;

  sec10Clk = 0;
  sec10Num = 0;
  sec10Trigger = 0;

  min1Clk = 0;
  min1Num = 0;
  min1Trigger = 0;

  min10Clk = 0;
  min10Num = 0;
  min10Trigger = 0;

  //Serial.begin(9600);
}

unsigned long comMilli = 0;

void loop() {
  // put your main code here, to run repeatedly:  
  
  TTL4790(&sec1Clk, &sec1Num, &sec1Trigger);
  TTL4750(&sec1Trigger, &sec10Num, &sec10Trigger);
  TTL4790(&sec10Trigger, &min1Num, &min1Trigger);
  TTL4750(&min1Trigger, &min10Num, &min10Trigger);
  
  if(comMilli > 15){
    FND_ComSel(0); 
    Disp_FND(~fnd_data[sec1Num]); 
  }
  else if(comMilli > 10){
    FND_ComSel(1); 
    Disp_FND(~fnd_data[sec10Num]); 
  }
  else if(comMilli > 5){
    FND_ComSel(2); 
    Disp_FND(~fnd_data[min1Num]);     
  }
  else if (comMilli > 0){
    FND_ComSel(3); 
    Disp_FND(~fnd_data[min10Num]);     
  }
}

void FND_ComSel(char com)
{
  if(com == 0){ // 1000의 자리 숫자 공통 단자 HIGH
    PORTB = 0x01;    
  }
  else if(com == 1){ // 100의 자리 숫자 공통 단자 HIGH
    PORTB = 0x02;
  }
  else if(com == 2){ // 10의 자리 숫자 공통 단자 HIGH
    PORTB = 0x04;
  }
  else if(com == 3){ // 1의 자리 숫자 공통 단자 HIGH
    PORTB = 0x08;
  }
}

void Disp_FND(char fnd)
{  
  PORTD = ~(fnd << 1);  
}

void TTL4790(char *clk, int *num, char *trigger){
  if(*clk){
    *num = *num + 1;
    if(*num == 10){
      *trigger = 1;
      *num = 0;
    }
    *clk = 0;
  }
}

void TTL4750(char *clk, int *num, char *trigger){
  if(*clk){
    *num = *num +1;
    if(*num == 6){
      *trigger = 1;
      *num = 0;
    }
    *clk = 0;
  }
}

unsigned long idx = 0;
unsigned long mil = 0;
ISR(TIMER2_COMPA_vect){
  idx++;
  mil++;
  comMilli++;
  if(idx > 100)  {
    sec1Clk = 1;
    idx = 0;    
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
