unsigned char num;
int state;

unsigned long startMilli;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  DDRD |= 0xF0;
  DDRB |= 0x0F;
  
  //PORTD = 0x0C;
  // 내부 풀업
  // 굳이 스위치에 HIGH를 연결하지 않아도 되긴한데 난 연결할거임
  
  EIMSK = 0x03;
  // INT1 INT0 을 사용하겠다 선언
  EICRA = 0x05;
  // INT1 INT0 의 작동방식을 CHANGE으로 설정
  SREG |= 0x80;
  // GLOBAL Interrupt Enable

  state = 0;
  
  num = 0x80;
  
  PORTD = ~num;
  PORTB = 0x0F;
}
unsigned long int0Milli = 0;
unsigned long int1Milli = 0;
// ISR INT0의 서브루틴 생성
ISR(INT0_vect){
  if(int0Milli == 0){
    int0Milli = millis();
  }
  else{
    if(millis() - int0Milli > 50){
      Serial.println("1");
      int0Milli = 0;
    }
  }
  state = 1;  
}

ISR(INT1_vect){
  if(int1Milli == 0){
    int1Milli = millis();
  }
  else{
    if(millis() - int1Milli > 50){
      Serial.println("2");
      int1Milli = 0;
    }
  }
  state = 2;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(startMilli == 0){
    startMilli = millis();
  }
  else{
    if(millis() - startMilli > 1000){      
      if(state == 1){
        if(num & 0x80){   
          num = 0x01;
        }
        else if(num & 0x08){
          num = 0x10;
        }
        else{
          num = num << 1;
        }
      }
      else if(state == 2){   
        if(num & 0x01){
          num = 0x80;
        }
        else if(num & 0x10){
          num = 0x08;
        }
        else{
          num = num >> 1;
        }
      }
      if(num & 0xF0){
        PORTD = ~num;
        PORTB = 0xFF;
      }
      else if(num & 0x0F){
        PORTD = 0xFF;
        PORTB = ~num;    
      }
      startMilli = 0;
    }
  }
}
