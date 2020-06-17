
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
  DDRC = 0xCC;
  PORTC = 0xFF;
  PORTD = 0x00;
}

char ch;

void loop() {
  // put your main code here, to run repeatedly:
  ch = UART_Getch();
  // 수신 될 데이터를 기다리고 받았으면 이를
  // char 형태로 반환
  UART_Putch(ch);
  // 수신 버퍼가 비였다면 이를 플래그로 사용하여
  // 데이터를 송신
}
