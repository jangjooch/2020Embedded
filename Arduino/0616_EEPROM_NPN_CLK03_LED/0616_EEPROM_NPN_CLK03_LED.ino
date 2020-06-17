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
  DDRB = 0x00;
  // PB 0 ~ 3 INPUT 버튼용
  // PB 4, 5 LED 예정
  PORTB = 0x0F;
  // 내부 풀업 사용
  
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

  //EEPROM_ALCall();
}

unsigned long comMilli = 0;
// FND 출력용
unsigned long term = 0;
// 초단위 시간 증가
unsigned long mil = 0;
// 실제 millis
unsigned long past_mill = 0;
// 디바운스용 mill

char button_al;
char button_next;
char button_up;

int buttonState = 0;

int SelectNum = 0;

void loop() {
  // put your main code here, to run repeatedly:  
  button_al = PINB & 0x01;
  button_next = PINB & 0x02;
  button_up = PINB & 0x04;
  
  if(button_al == 0){
    if(past_mill == 0){
      past_mill = mil;
    }
    else{
      if(mil - past_mill > 50){
        buttonState = 1;
        past_mill = 0;
        Serial.println("ButtonAL");
      }
      else{
        buttonState = 0;
        past_mill = 0;
      }
    }
  }

  if(button_next == 0){
    if(past_mill == 0){
      past_mill = mil;
    }
    else{
      if(mil - past_mill > 50){
        buttonState = 2;
        past_mill = 0;
        Serial.println("ButtonNEXT");
      }
      else{
        buttonState = 0;
        past_mill = 0;
      }
    }
  }

  if(button_up == 0){
    if(past_mill == 0){
      past_mill = mil;
    }
    else{
      if(mil - past_mill > 50){
        buttonState = 3;
        past_mill = 0;
        Serial.println("ButtonUP");
      }
      else{
        buttonState = 0;
        past_mill = 0;
      }
    }
  }
  
  if(buttonState == 1){
    Serial.println("State Activate");
    if(state){
      // 여기에 AL 저장 만들어야됨
      //EEPROM_ALSet();
      state = 0;
    }
    else{
      state = 1;
      al_hour10 = hour10Num;
      al_hour1 = hour1Num;
      al_min10 = min10Num;
      al_min1 = min1Num;
    }
    buttonState = 0;
  }
  
  if(state){
    if(buttonState == 2){
      Serial.println("NEXT Activate"); 
      Button_NEXT();
      buttonState = 0;
    }
    else if(buttonState == 3){
      Serial.println("UP Activate");
      Button_UP();
      buttonState = 0;
    }
    AL_Time();
  }
  else{
    Nomal_Time();
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

void TTL4710(char *clk, int *num, char *trigger){
  if(*clk){
    *num = *num +1;
    if(*num == 2){
      *trigger = 1;
      *num = 0;
    }
    *clk = 0;
  }
}


// 1ms 단위로 진행
ISR(TIMER2_COMPA_vect){
  term++;
  mil++;
  comMilli++;
  if(term > 1000)  {
    min1Clk = 1;
    term = 0;
    /*
    Serial.print("NOMAL : ");
    Serial.print(hour10Num);
    Serial.print(" ");
    Serial.print(hour1Num);
    Serial.print(" ");  
    Serial.print(min10Num);
    Serial.print(" ");
    Serial.println(min1Num);
    Serial.print("AL : ");
    Serial.print(al_hour10);
    Serial.print(" ");
    Serial.print(al_hour1);
    Serial.print(" ");  
    Serial.print(al_min10);
    Serial.print(" ");
    Serial.println(al_min1);
    */
  }
  if(comMilli >= 4){
    comMilli = 0;
  }
}

unsigned long MyMillis(){
  return mil;
}

void Nomal_Time(){
  TTL4790(&min1Clk, &min1Num, &min1Trigger);
  TTL4750(&min1Trigger, &min10Num, &min10Trigger);
  TTL4790(&min10Trigger, &hour1Num, &hour1Trigger);
  TTL4710(&hour1Trigger, &hour10Num, &hour10Trigger);  

  if(hour10Num == 1 && hour1Num == 3){
    hour10Num = 0;
    hour1Num = 1;
  }
  if(comMilli == 3 ){
    FND_ComSel(0); 
    Disp_FND(~fnd_data[min1Num]); 
  }
  else if(comMilli == 2){
    FND_ComSel(1); 
    Disp_FND(~fnd_data[min10Num]); 
  }
  else if(comMilli == 1){
    FND_ComSel(2); 
    Disp_FND(~fnd_data[hour1Num]);     
  }
  else if (comMilli == 0){
    FND_ComSel(3); 
    Disp_FND(~fnd_data[hour10Num]);     
  }
}
void AL_Time(){  
  if(comMilli == 3 ){
    FND_ComSel(0); 
    Disp_FND(~fnd_data[al_min1]); 
  }
  else if(comMilli == 2){
    FND_ComSel(1); 
    Disp_FND(~fnd_data[al_min10]); 
  }
  else if(comMilli == 1){
    FND_ComSel(2); 
    Disp_FND(~fnd_data[al_hour1]);     
  }
  else if (comMilli == 0){
    FND_ComSel(3); 
    Disp_FND(~fnd_data[al_hour10]);     
  }
}

void Button_NEXT(){
  SelectNum++;
  if(SelectNum >= 4){
    SelectNum = 0;
  }
}
void Button_UP(){
  /**/
  if(SelectNum == 0){    
    al_hour10++;
    if(al_hour10 >= 2){
      al_hour10 = 0;
    }
  }
  else if(SelectNum == 1){
    al_hour1++;
    if(al_hour10 == 1){
      if(al_hour1 >= 3){
        al_hour1 = 0;
      }
    }
    else{
      if(al_hour1 >= 10){
        al_hour1 = 0;
      }
    }
  }
  else if(SelectNum == 2){
    al_min10++;
    if(al_min10 >= 6){
      al_min10 = 0;
    }    
  }
  else if(SelectNum == 3){
    al_min1++;
    if(al_min1 >= 10){
      al_min1 = 0;
    }    
  }
}

void EEPROM_ALSet(){
  int address = 0;
  
  //EEPROM_Write(address, state);  
  // address += sizeof(state);
  EEPROM_Write(address, al_hour10);  
  
  address += sizeof(al_hour10);
  EEPROM_Write(address, al_hour1);
  
  address += sizeof(al_hour1);
  EEPROM_Write(address, al_min10);
  
  address += sizeof(al_min10);
  EEPROM_Write(address, al_min1);  
}



void EEPROM_ALCall(){
  int address = 0;  
  
  int get_num = EEPROM_Read(address);
  al_hour10 = get_num;  
  address += sizeof(unsigned char);

  get_num = EEPROM_Read(address);
  al_hour1 = get_num;
  address += sizeof(unsigned char);

  get_num = EEPROM_Read(address);
  al_min10 = get_num;
  address += sizeof(unsigned char);

  get_num = EEPROM_Read(address);
  al_min1 = get_num;

}

void EEPROM_Write(int address, char data){
  //Serial.println("Write Start");
  while((EECR & 0x02) ){
    // EEWE 0인지 확인하도록 delay
  }
  EEAR = address;
  EEDR = data;
  EECR |= 0x04; // EEMWE 1 Set
  EECR |= 0x02; // EEWE 1 Set
  // 동시에 하면 안된다. EEMWE가 Set되어야
  // Write하겠다는 암시를 하는 것이다.
  // 이후 Write가 완료되면 HW적으로 0 Clear 된다.
  //Serial.println("Write Done");
}

char EEPROM_Read(int address){
  //Serial.println("Read Start");
  while((EECR & 0x02) ){
    // EEWE 0인지 확인하도록 delay
  }
  EEAR = address;
  EECR |= 0x01; // EERE 1 Set
  char data = EEDR;
  //Serial.println("Read Done");
  return data;  
}
