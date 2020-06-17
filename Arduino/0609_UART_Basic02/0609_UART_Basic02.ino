
char UART_Getch(void){
  while(!(UCSR0A & 0x80)){
    // 수신을 기다림
    // 수산 데이터가 Set이 될때까지 기다린다.
  }
  return UDR0;
  // UDR0을 읽으면 RX 버퍼를 읽는 것과 같다.
}

void UART_Putch(char tx){
  while(!(UCSR0A & 0x20)){
    // 버퍼가 비일때까지 while
  }
  
  UDR0 = tx;  
}

void setup() {
  // put your setup code here, to run once:
  UCSR0A = 0x00;
  // USCR0A 는 플래그비트를 읽는 것이 목적이기 때문에
  // 설정할 것이 없다.
  UCSR0B = 0x18;
  // 수신완료 Interrupt Enable
  // 송신완료 Interrupt Enable 
  UCSR0C = 0x06;
  // 정지 비트 0 default
  // 데이터 비트 1 1 8bit 설정
  UBRR0H = 0;
  UBRR0L = 103;
  // bps 9600 설정

  DDRD = 0xFF;
  DDRC = 0x0F;
  PORTC = 0xFF;
  PORTD = 0x00;
}

char ch;

void loop() {
  // put your main code here, to run repeatedly:
  char ch;
  ch = UART_Getch();
  // 데이터를 계속 읽는다.
  if(ch >= '0' && ch <= '9'){
    ch = ch - '0';
    // 읽은 데이터의 아스키 값이 0 ~ 9일때
    // 읽었던 이 값을 -'0' 함으로서 실제
    // 숫자값을 가져와 이를 기반으로 점멸한다.
    for(int i = 0 ; i < ch ; i++){
      PORTD = 0xFF;
      delay(100);
      PORTD = 0x00;
      delay(100);
    }
  }
}
