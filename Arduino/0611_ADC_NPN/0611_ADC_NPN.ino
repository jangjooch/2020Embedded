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

char fnd_data[10] = 
{0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92,
  0x82, 0xF8, 0x80, 0x90}; 

int ad = 0;
int num0 = 0;
int num1 = 0;
int num2 = 0;
int num3 = 0;

char sendData[4] = {0,};
int sendIdx = 3;

int Trigger = 1;

void setup() {
  // put your setup code here, to run once:

  DDRD = 0xFF;
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

  
  DDRC = 0x00;
  //PORTC = 0x01;
  // Analog Pin INTPUT
  ADMUX = 0x40;
  // AREF 단자 전압이용 및 AREF단자 와 GND 사이를 콘센터로 접속
  ADCSRA = 0x87;
  // ADEnable
  // 분주율 128

  UCSR0B = 0x98;
  // Serial interrupt enable
  // RX TX Enable
  UBRR0 = 103; //Serial bps설정
  //Serial.begin(9600);
  delay(5);
}

unsigned long comMilli = 0;

void loop() {
  // put your main code here, to run repeatedly:  
  if(Trigger){
    ADCSRA = 0xC7;
    Trigger = 0;
    while( ( (ADCSRA & 0x40) != 0)){
      // AD변환이 끝나 0이 되었을때
    }
    ad = (int)ADCL + (int)(ADCH << 8);
    num3 = ad/1000;
    ad = ad - (num3 * 1000);
    num2 = ad/100;
    ad = ad - (num2 * 100);
    num1 = ad/10;
    num0 = ad%10;
    ADCSRA = 0x87;
    //Serial.println(ad);
    //Trigger = 1;
    putch();
  }
  
  // 단일모드 AD시작
  
}

void putch(){
  sendData[3] = num3 + '0';
  sendData[2] = num2 + '0';
  sendData[1] = num1 + '0';
  sendData[0] = num0 + '0';
  UCSR0B |= 0x20;
}
char nextLine = 1;

// 읽은 데이터가 보내는 데이터가 같다면 Interrupt Disable


ISR(USART_UDRE_vect){
  if(nextLine){
    char ch = sendData[sendIdx];  
    sendIdx --;
    UDR0 = ch;
    if(sendIdx < 0){
      nextLine = 0;
    }
  }
  else{
    char ch = '\n';
    UDR0 = ch;
    nextLine = 1;
    Trigger = 1;
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

unsigned long idx = 0;
unsigned long mil = 0;
ISR(TIMER2_COMPA_vect){
  idx++;  
  comMilli++;  
  if(comMilli>20){
    comMilli = 0;
  }
  if(comMilli > 15){
    FND_ComSel(0); 
    Disp_FND(~fnd_data[num3]); 
  }
  else if(comMilli > 10){
    FND_ComSel(1); 
    Disp_FND(~fnd_data[num2]); 
  }
  else if(comMilli > 5){
    FND_ComSel(2); 
    Disp_FND(~fnd_data[num1]);     
  }
  else{
    FND_ComSel(3); 
    Disp_FND(~fnd_data[num0]);     
  }  
}
