unsigned int fnd_a = 1;
unsigned int fnd_b = 2;
unsigned int fnd_c = 3;
unsigned int fnd_d = 4;
unsigned int fnd_e = 5;
unsigned int fnd_f = 6;
unsigned int fnd_g = 7;

unsigned char fnd_data[10] = 
{0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92,
  0x82, 0xF8, 0x80, 0x90}; 

int state = 0;
// 0 : normal
// 1 : AL


unsigned char min1Num = 0;
unsigned char min10Num = 0;
unsigned char hour1Num = 2;
unsigned char hour10Num = 1;

unsigned char RealTime_Set = 0;
unsigned char al_hour10 = 0;
unsigned char al_hour1 = 0;
unsigned char al_min10 = 0;
unsigned char al_min1 = 0;


unsigned long comMilli = 0;
// FND 출력용
unsigned long term = 0;
// 초단위 시간 증가
unsigned long mil = 0;
// 실제 millis

unsigned long pastAL = 0;
unsigned long pastNEXT = 0;
unsigned long pastUP = 0;

int SelectNum = 0;
// 0 1 2 3

void setup() {
  Serial.begin(9600);
  Serial.println("start");
  // put your setup code here, to run once:
  
  DDRD = 0xFF;  
  DDRC = 0x0F;
  
  DDRB = 0x07;
  // 0000 0111
  PORTB = 0x38;
  // 버튼용 내부풀업
  // 0011 1000
  
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
  // 상한 값 설정


  Serial.println("start");

  Serial.println("EEPROM ALCall");

  EEPROM_ALCall();
  if(RealTime_Set == 0){
    // 시간이 설정되지 않은 상태
    Serial.println("RealTime_Set");    
    min1Num = 0;
    min10Num = 0;
    hour1Num = 2;
    hour10Num = 1;
    while(RealTime_Set == 0){
        // 현재 시간 설정 loop
      if( (PINB & 0x08) == 0){
        if(pastAL == 0){
          pastAL = mil;
        }
      }
      else{
        if(pastAL != 0){
          if(mil - pastAL > 50){
            pastAL = 0;
            Serial.println("Button AL");
            Serial.println("RealTime_Set");
            RealTime_Set = 1;
            ds1302Set();
            pastAL = 0;
            pastNEXT = 0;
            pastUP = 0;
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
            Serial.println("Button NEXT");
            button_next();
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
            Serial.println("Button UP");
            button_up();
          }
        }
      }      
      Nomal_Time();
    }
  }  
}

void loop() {
  if(state){
    // AL
  }
  else{
    // Nomal
      if( (PINB & 0x08) == 0){
        if(pastAL == 0){
          pastAL = mil;
        }
      }
      else{
        if(pastAL != 0){
          if(mil - pastAL > 50){
            pastAL = 0;
            Serial.println("Button AL");
            pastAL = 0;
          }
        }
      }
    Nomal_Time();
  }  
}


void ds1302init(){
  DDRB |= 0x07;
  // output Set
  PORTB &= ~(0b00000010);
  // I/O 0 Clear
}

void ds1302Set(){
  ds1302init();
  delayMicroseconds(1);
  ds1302Write(7,0b00000000); // WP 0 Clear
  // Write Protect는 Default가 없으므로 설정해야한다.
  delayMicroseconds(1);
  ds1302Write(0,0); // sec
  delayMicroseconds(1);
  
  
  unsigned char minSet = 0;
  minSet |= min1Num;
  minSet |= (min10Num << 4);
  ds1302Write(7,0b00000000); // WP 0 Clear
  ds1302Write(1,minSet); // min
  delayMicroseconds(1);

  unsigned char hourSet = 0;
  hourSet |= hour1Num;
  hourSet |= (hour10Num << 4);
  ds1302Write(7,0b00000000); // WP 0 Clear
  ds1302Write(2,hourSet); // hour
  delayMicroseconds(1);
  
  ds1302Write(7,0b00000000); // WP 0 Clear
  ds1302Write(3,0b00010001); // date
  delayMicroseconds(1);
  ds1302Write(7,0b00000000); // WP 0 Clear
  ds1302Write(4,0b00000101); // month
  delayMicroseconds(1);
  ds1302Write(7,0b00000000); // WP 0 Clear
  ds1302Write(5,0b00100001); // year
  delayMicroseconds(1);
  Serial.println("Write Done");
}

void ds1302Write(unsigned char add, char data){
  unsigned char valx = 0x80;
  // 기본 Write 단위
  unsigned ucLoop = 0x00;
  valx = (valx | (1 << add));
  // 주소 추가
  ds1302init();
  // 안전용
  PORTB = PORTB | 0b00000100;
  // 보내겠다고 신호 RST Set
  
  delayMicroseconds(1); ;
  // 명령어 Send
  for(ucLoop = 0; ucLoop < 8 ; ucLoop++){
    // 작성된 명령어에 따라 출력하기
    if( (valx&0x01) ){
      // LSB 가져오기
      PORTB = PORTB | 0b00000010;
    }
    else{
      PORTB = PORTB & ~(0b00000010);
    }

    // CLK 생성
    PORTB = PORTB | 0b00000001;
    // 상승엣지
    delayMicroseconds(1);
    PORTB = PORTB & ~(0b00000001);
    
    valx = valx >> 1;
  }

  // 데이터 전송
  for(ucLoop = 0; ucLoop < 8 ; ucLoop++){
    if(data & 0x01){
      // LSB부터 읽어 전송한다.
      PORTB = PORTB | 0b000000010;
    }
    else{
      PORTB = PORTB & ~(0b000000010);
    }

    PORTB |= 0b00000001; // 상승엣지
    delayMicroseconds(1);
    PORTB &= ~(0b00000001);
    data = data >> 1;
  }
  
  PORTB &= ~(0b00000100);
  // RST Clear
}

unsigned char ds1302Read(unsigned char add){
  unsigned char valx = 0x81;
  // Read 기본 0x81 설정
  unsigned char ucLoop = 0x00;
  PORTB |= (0b00000100);
  // RST Set
  valx = (valx | (1 << add));
  // 원하는 값에 따라 주소 Set
  delayMicroseconds(1); ;
  // min hour에 따른 +
  //  2    4
  for(ucLoop = 0 ; ucLoop < 8 ; ucLoop++){
    // LSB부터 명령어 전송
    // 명령어 부분
    if((valx & 0x01)){
      // 해당 비트가 1일경우 HIGH 출력
      // LSB 읽기
      PORTB |= 0b00000010;
      // DAT Set
    }
    else{
      PORTB &= ~(0b00000010);
      // DAT Clear
    }

    // CLK 생성
    PORTB |= 0b00000001;
    // CLK Set 상승엣지
    delayMicroseconds(1); ;
    PORTB &= ~(0b00000001);
    // CLK Clear;
    
    valx = valx >> 1;
    // 비트 이동
  }
  //PORTB = PORTB & ~(0b00000010);  
  // 명령어 보냈으니 이제 읽어야지
  DDRB &= ~(0b00000010);
  // Set PortPin as INPUT
  
  valx = 0x00;
  
  for(ucLoop = 0; ucLoop < 8 ; ucLoop++){
    // CLK 생성
    PORTB &= ~(0b00000001); // 하강엣지 생성
    // CLK CLR
    delayMicroseconds(1); ;
    PORTB |= 0b00000001;
    // CLK Set

    // 데이터 읽기
    if( (PINB & 0b00000010)){
      // DAT 핀에 들어오는 정보가 1이라면
      valx |= 0x80;
    }
    delayMicroseconds(1); ;
    if(ucLoop < 7){
      valx = valx >> 1;
    }
  }
  delayMicroseconds(1); ;
  DDRB |= 0x02;
  // DAT핀 OUTPUT
  PORTB &= ~(0b00000100);
  // RST Clear
  return valx;
}

void Term_CLK(int a){
  for(int i = 0 ; i < a ; i++){
    PORTB |= 0b00000001; // 상승엣지
    delayMicroseconds(1);
    PORTB &= ~(0b00000001);    
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

// 1ms 단위로 진행
ISR(TIMER2_COMPA_vect){
  term++;
  mil++;
  comMilli++;
  if(term > 1000)  {
    if(RealTime_Set){
      unsigned char sec_get = ds1302Read(0);
      Term_CLK(5);
      unsigned char min_get = ds1302Read(1);
      Term_CLK(5);
      unsigned char hour_get = ds1302Read(2);
      Serial.print("sec_get : ");
      Serial.println(sec_get, HEX);
      Serial.print("min_get : ");
      Serial.println(min_get, HEX);
      Serial.print("hour_get : ");
      Serial.println(hour_get, HEX);
      Serial.println("------");
      min1Num = (min_get & 0x0F);
      min10Num = (min_get & 0xF0) >> 4;
      hour1Num = (hour_get & 0x0F);
      hour10Num = (hour_get & 0xF0) >> 4;
    }
    term = 0;
  }
  if(comMilli >= 4){
    comMilli = 0;
  }
}

unsigned long MyMillis(){
  return mil;
}

void Nomal_Time(){
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


void button_al(){
  if(state){
    state = 0;
  }
  else{
    state = 1;
  }
}

void button_next(){
  SelectNum++;
  if(SelectNum >= 4){
    SelectNum = 0;
  }
}

void button_up(){
  if(SelectNum == 0){
    hour10Num++;
    if(hour10Num > 1){
      hour10Num = 0;
    }
  }
  else if(SelectNum == 1){
    hour1Num++;
    if( (hour10Num == 1) && (hour1Num > 2) ){
      hour1Num = 0;
    }
    else if(hour1Num > 9){
      hour1Num = 0;
    }
  }
  else if(SelectNum == 2){
    min10Num++;
    if(min10Num > 5){
      min10Num = 0;
    }
  }
  else if(SelectNum == 3){
    min1Num++;
    if(min1Num > 9){
      min1Num = 0;
    }
  }
}



void EEPROM_ALCall(){
  int address = 0;  
  
  unsigned char get_num = EEPROM_Read(address);
  RealTime_Set = get_num;  
  address += sizeof(RealTime_Set);

  get_num = EEPROM_Read(address);
  al_hour10 = get_num;
  address += sizeof(al_hour10);

  get_num = EEPROM_Read(address);
  al_hour1 = get_num;
  address += sizeof(al_hour1);

  get_num = EEPROM_Read(address);
  al_hour1 = get_num;
  address += sizeof(al_hour1);

  get_num = EEPROM_Read(address);
  al_min1 = get_num;
}

void EEPROM_ALSet(){
  int address = 0;
  
  EEPROM_Write(address, RealTime_Set);
  
  address += sizeof(RealTime_Set);  
  EEPROM_Write(address, al_hour10);  
  
  address += sizeof(al_hour10);
  EEPROM_Write(address, al_hour1);
  
  address += sizeof(al_hour1);
  EEPROM_Write(address, al_min10);
  
  address += sizeof(al_min10);
  EEPROM_Write(address, al_min1);  
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
