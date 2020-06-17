
char UART_Getch(void){
  while(!(UCSR0A & 0x80)){
    // 수신을 기다림
    // 수산 데이터가 Set이 될때까지 기다린다.
  }
  return UDR0;
  // UDR0을 읽으면 RX 버퍼를 읽는 것과 같다.
}

char UART_Gets(char buf[]){
  // 시리얼 모니터 옵션 새줄을 통해 받으면
  // \n 이 붙어서 오기때문에 이를 기반으로
  // 데이터 끝임을 확인한다.
  int i = 0;
  char ch;
  while((ch = UART_Getch()) != '\n'){
    // \n 이 나오기 전까지 받아 buf에 받는다.
    buf[i] = ch;
    i++;
  }
  // 데이터 끝이라는 의미로 0을 주는 것이다.
  buf[i] = 0;  
  
}

void UART_Putch(char tx){
  while(!(UCSR0A & 0x20)){
    // 버퍼가 비일때까지 while
  }  
  UDR0 = tx;
  // char 단위로 읽는 것이기 때문에
  // 시리얼 모니터에서 입력하면
  // 한 글자당 처리한다.
}

void UART_Puts(char buf[]){
  int i = 0;
  while(buf[i] != 0){
    UART_Putch(buf[i]);
    i++;
  }
  UART_Putch('\n');
  // 받는 측에서도 되도록
}

void setup() {
  // put your setup code here, to run once:
  UCSR0A = 0x00;
  // USCR0A 는 플래그비트를 읽는 것이 목적이기 때문에
  // 설정할 것이 없다.
  UCSR0B = 0x18;
  // RX TX Enable
  UCSR0C = 0x06;
  // 정지 비트 0 default
  // 데이터 비트 1 1 8bit 설정
  // -> default라 설정하지 않아도 된다.
  UBRR0H = 0;
  UBRR0L = 103;
  // bps 9600 설정

  // Falling 방식으로 UART 통신을 하는 것이다.
  
  DDRD = 0xFF;
  DDRC = 0x0F;
  PORTC = 0xFF;
  PORTD = 0x00;
}

void loop() {
  // put your main code here, to run repeatedly:
  char buf[50];
  UART_Gets(buf);
  UART_Puts(buf);  
}
