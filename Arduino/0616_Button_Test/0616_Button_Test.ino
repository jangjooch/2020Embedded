int fnd_a = 1;
int fnd_b = 2;
int fnd_c = 3;
int fnd_d = 4;
int fnd_e = 5;
int fnd_f = 6;
int fnd_g = 7;

char fnd_data[10] = 
{0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92,
  0x82, 0xF8, 0x80, 0x90}; 

int state = 0;
// 0 : normal
// 1 : AL

char min1Clk = 0;
int min1Num = 0;
char min1Trigger = 0;

char min10Clk = 0;
int min10Num = 0;
char min10Trigger = 0;

char hour1Clk = 0;
int hour1Num = 2;
char hour1Trigger = 0;

char hour10Clk = 0;
int hour10Num = 1;
char hour10Trigger = 0;

int al_hour10 = 0;
int al_hour1 = 0;
int al_min10 = 0;
int al_min1 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("start");
  // put your setup code here, to run once:
  
  DDRD = 0xFF;  
  DDRC = 0x0F;

  // 0000 0111
  DDRB = 0x07;
  // PB 0 ~ 3 INPUT 버튼용
  // 0011 1000
  PORTB = 0x38;
  // 내부풀업
  
  SREG |= 0x80;
  // Interrupt Enable
  TCCR2A = 0x42;
  // 4 : Set 될 시 CTC ON
  // 2 : CTC모드
  TCCR2B = 0x86;
  // CTC 모드 설정
  // 분주율 64
  TIMSK2 = 0x02;
  // OCIE2A EnAble
  OCR2A = 249;
  // 상한 값 출력

  //EEPROM_ALCall();
}

unsigned long comMilli = 0;
// FND 출력용
unsigned long term = 0;
// 초단위 시간 증가
unsigned long mil = 0;
// 실제 millis

unsigned long pastAL = 0;
unsigned long pastNEXT = 0;
unsigned long pastUP = 0;

int buttonState = 0;

int SelectNum = 0;

void loop() {
  // put your main code here, to run repeatedly:  
  //Serial.println(PINB & 0x01);
  if( (PINB & 0x08) == 0){
    if(pastAL == 0){
      pastAL = mil;
    }
  }
  else{
    if(pastAL != 0){
      if(mil - pastAL > 50){
        pastAL = 0;
        Serial.println("AL");
      }
    }
  }
  
  if( (PINB & 0x10) == 0){
    if(pastNEXT == 0){
      pastNEXT = mil;
    }
  }
  else{
    if(pastNEXT != 0){
      if(mil - pastNEXT > 50){
        pastNEXT = 0;
        Serial.println("NEXT");
      }
    }
  }
  
  if( (PINB & 0x20) == 0){
    if(pastUP == 0){
      pastUP = mil;
    }
  }
  else{
    if(pastUP != 0){
      if(mil - pastUP > 50){
        pastUP = 0;
        Serial.println("UP");
      }
    }
  }
}


// 4ms 단위로 진행
ISR(TIMER2_COMPA_vect){
  //Serial.println("Tik");
  mil++;
}

unsigned long MyMillis(){
  return mil;
}
