unsigned char led;
int idx;
unsigned long pasted = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  led = 0x01;
  idx = 0;
  SREG |= 0x80;
  // Global Interrupt Enable
  
  TCCR2A = 0x02;
  // WGM21 WGM20
  TCCR2B = 0x07;
  // WGM22 CS02 CS01 CS00
  // CTC 모드
  // 분주율 1 1 1 1024설정
  TIMSK2 = 0x02;
  // OCIE2A EnAble
  OCR2A = 0xFF;
  // 상한값 설정  
  DDRB = 0x0F;
  DDRC = 0x0F;
}

ISR(TIMER2_COMPA_vect){  
  // 실행 될때마다 시작값을 다시 설정하여야 한다.
  idx++;
  if(idx > 60){
    // 이렇게 하면 거의 1초 나옴
    if(pasted == 0){
      pasted = millis();
    }
    else{
      Serial.println(millis() - pasted);
      pasted = 0;
    }
    
    if(led == 0x01){
      led = 0x80;
    }
    else{
      led = led >> 1;
    }
    idx = 0;
  }    
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTC = ~led;
  PORTB = ~(led >> 4);
}
