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

char min1Clk = 0;
int min1Num = 0;
char min1Trigger = 0;

char min10Clk = 0;
int min10Num = 0;
char min10Trigger = 0;

char hour1Clk = 0;
int hour1Num = 0;
char hour1Trigger = 0;

char hour10Clk = 0;
int hour10Num = 0;
char hour10Trigger = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("start");
  // put your setup code here, to run once:
  
  DDRD = 0xFF;  
  DDRC = 0x0F;
  DDRB = 0xFF;
  
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

  EEPROM_TimeSet();
}

unsigned long comMilli = 0;

void loop() {
  // put your main code here, to run repeatedly:  
  
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

unsigned long idx = 0;
unsigned long mil = 0;
// 1ms 단위로 진행
ISR(TIMER2_COMPA_vect){
  idx++;
  mil++;
  comMilli++;
  if(idx > 1000)  {
    min1Clk = 1;
    idx = 0;
    Serial.print(hour10Num);
    Serial.print(" ");
    Serial.print(hour1Num);
    Serial.print(" ");  
    Serial.print(min10Num);
    Serial.print(" ");
    Serial.println(min1Num);
  }
  if(comMilli >= 4){
    comMilli = 0;
  }
}

unsigned long MyMillis(){
  return mil;
}

void EEPROM_TimeSet(){
  int address = 0;  
  
  int get_num = EEPROM_Read(address);
  state = get_num;  
  address += sizeof(unsigned char);
  Serial.println(state);

  get_num = EEPROM_Read(address);
  hour10Num = get_num;
  address += sizeof(unsigned char);
  Serial.println(hour10Num);

  get_num = EEPROM_Read(address);
  hour1Num = get_num;
  address += sizeof(unsigned char);
  Serial.println(hour1Num);

  get_num = EEPROM_Read(address);
  min10Num = get_num;
  address += sizeof(unsigned char);
  Serial.println(min10Num);

  get_num = EEPROM_Read(address);
  min1Num = get_num; 
  Serial.println(min1Num); 
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
