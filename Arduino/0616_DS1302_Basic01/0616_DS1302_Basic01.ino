int fnd_a = 1;
int fnd_b = 2;
int fnd_c = 3;
int fnd_d = 4;
int fnd_e = 5;
int fnd_f = 6;
int fnd_g = 7;

unsigned char fnd_data[10] = 
{0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92,
  0x82, 0xF8, 0x80, 0x90}; 

int state = 0;
// 0 : normal
// 1 : AL

char min1Clk = 0;
unsigned int min1Num = 0;
char min1Trigger = 0;

char min10Clk = 0;
unsigned int min10Num = 0;
char min10Trigger = 0;

char hour1Clk = 0;
unsigned int hour1Num = 2;
char hour1Trigger = 0;

char hour10Clk = 0;
unsigned int hour10Num = 1;
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
  ds1302init();
  delayMicroseconds(1);
  ds1302Write(7,0b00000000); // WP 0 Clear
  // Write Protect는 Default가 없으므로 설정해야한다.
  delayMicroseconds(1);
  ds1302Write(0,0); // sec
  delayMicroseconds(1);
  ds1302Write(7,0b00000000); // WP 0 Clear
  ds1302Write(1,0b00000111); // min
  delayMicroseconds(1);
  ds1302Write(7,0b00000000); // WP 0 Clear
  ds1302Write(2,0b00000010); // hour
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
  
  // 1 = min
  // 2 = hour
  Serial.println("Write Done");
    
  unsigned char min_get = ds1302Read(1);
  delayMicroseconds(1);
  unsigned char hour_get = ds1302Read(2);
  delayMicroseconds(1);
  Serial.println("Read Done");
  
  Serial.println(min_get, HEX);
  Serial.println(hour_get, HEX);
}

unsigned long comMilli = 0;
// FND 출력용
unsigned long term = 0;
// 초단위 시간 증가
unsigned long mil = 0;
// 실제 millis

void loop() {
  // put your main code here, to run repeatedly:    
  Nomal_Time();
}
void ds1302init(){
  DDRB = 0x0F;
  // output Set
  PORTB = 0x00;
  // I/O 0 Clear
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
      PORTB = PORTB | 0b00000010;
      // DAT Set
    }
    else{
      PORTB = PORTB & ~(0b00000010);
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
    PORTB = PORTB & ~(0b00000001);
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
    term = 0;
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
    min1Num = min_get %10;
    min10Num = min_get/10;
    hour1Num = hour_get % 10;
    hour10Num = hour_get / 10;
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

void Term_CLK(int a){
  for(int i = 0 ; i < a ; i++){
    PORTB |= 0b00000001; // 상승엣지
    delayMicroseconds(1);
    PORTB &= ~(0b00000001);    
  }
}
