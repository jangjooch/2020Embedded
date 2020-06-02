unsigned char num;
char state;
void setup() {
  // put your setup code here, to run once:
  DDRD = 0xFF;
  DDRB = 0xF9;
  // 2, 3번 비트에 0을 주어 PORTB1, 2를 입력으로 설정한다.
  PORTB = 0x06;
  // 이렇게 하면 굳이 내가 실제 보드에서 풀업을
  // 하지 않아도 내부 풀업을 사용할 수 있다.
  // 즉 위의 코드는 PORTB의 2, 3번째 비트에 내부 풀업을
  // 활성화 하겠다는 것을 의미한다.
  num = 0x08;
  state = 0;
  // DDRx 는 방향레지스터로 1은 출력, 0은 입력을 의미합니다.
  // 이후 x의 값에 따라 PORTx를 정하고 값을 출력 혹은 입력받을 수 있습니다.
}

unsigned long startMilli;

void loop() {
  // put your main code here, to run repeatedly:
  
  PORTD = ~num;
  // Active LOW이기때문에 not 연산을 통해 변환된 값을 PORTB에 출력합니다.
  
  char sw1 = (PINB & 0x02);
  // 실제로 PINB는 8bit를 읽습니다. 즉 0x00001111 이러한 형태로 읽습니다.
  // datasheet Arduino Uno와 Atmega 328를 확인하세요
  // 즉 위 코드는 PINB와 0000 0010을 AND를 통해 PINB의 2번째 비트의 값을 가져오겠다는 것을 의미합니다.
  // 데이터 시트 Arduino Uno를 확인하시면 PB1은 9번 핀과 연결되어 있음을 확인할 수 있습니다.
  char sw2 = (PINB & 0x04);
  if(sw1 == 0){
    // Active LOW이기 때문에 버튼을 눌렀을때는 LOW의 입력이 들어옵니다.
    state = 1;
  }
  else if(sw2 == 0){
    state = 2;
  }

  // delay를 사용하지 않고 LED를 밝히는 기준 num만 변화시키기 위한 코드입니다.
  if(startMilli == 0){
    startMilli = millis();
  }
  else{
    if(millis() - startMilli > 1000){
      if(state == 1){    
        if(num & 0x80){
          // num의 값과 0x80과 AND연산을 통해 8번째 비트의 값만 가져와
          // 8번째 비트의 값을 확인할 수 있습니다.
          num = 0x01;
        }
        else{
          num = num << 1;
        }
      }
      else if(state == 2){    
        if(num & 0x01){
          num = 0x80;
        }
        else{
          num = num >> 1;
        }
      }
      startMilli = 0;
    }
  }
}
