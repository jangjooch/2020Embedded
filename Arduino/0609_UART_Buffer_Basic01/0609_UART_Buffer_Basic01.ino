char buf[16];
char buf_length = 16;
char head, tail;
bool bFull, bEmpty;

void setup() {
  // put your setup code here, to run once:
  
  SREG |= 0x80;
  // Interrupt Enable
  
  UCSR0A = 0x00;
  // USCR0A 는 플래그비트를 읽는 것이 목적이기 때문에
  // 설정할 것이 없다.
  UCSR0B = 0x98;
  // 수신완료 Interrupt Enable
  // RX TX Enable
  UCSR0C = 0x06;
  // 정지 비트 0 default
  // 데이터 비트 1 1 8bit 설정
  // -> default라 설정하지 않아도 된다.
  UBRR0H = 0;
  UBRR0L = 103;
  // bps 9600 설정

  head = tail = 0;
  bFull = false;
  bEmpty = true;
}
ISR(USART_RX_vect){
  //char ch;
  //ch = UDR0;
  // 수신 인터럽트 시 데이터 저장
  //UART_Putch(ch);
  // 데이터 송신
  //UART_Puts();
  char ch = UDR0;
  if(bFull == false){
    head++;
    bEmpty = false;    
    if(head == buf_length){
      head = 0;
    }    
    buf[head] = ch;
    if((head == tail) && (bFull == false)){
      bFull = true;      
    }
  }
}
char Rx_Available(){
  if(head > tail){ // 출력될 글자의 수
    return (head - tail);
  }
  else if(tail > head){
    return(buf_length - tail + head); // 출력될 글자의 수
  }
  else{
    if(bFull){
      return buf_length;
    }
    else{
      return 0;
    }
  }
}

char UART_GetChar(){  
  char ch;
  if(bEmpty == false){
    ch = buf[tail];
    tail++;
    if(tail == buf_length){
      tail = 0;
    }
    if(tail == head){
      bEmpty = true;
      // 데이터를 다 읽음
    }
    bFull = false;
    return ch;
  }
  else{
    return 0;
  }
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

void loop() {
  // put your main code here, to run repeatedly:
  if(Rx_Available()){
    char getch = UART_GetChar();    
    UART_Putch(getch);
    //UART_Putch('a');
  }
}
