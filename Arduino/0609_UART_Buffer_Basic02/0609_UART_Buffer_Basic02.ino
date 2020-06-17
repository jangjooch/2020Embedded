char buf[30];
char buf_length = 30;
char data_length = 0;
char trigger = 0;

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

}
bool maxLength = false;
ISR(USART_RX_vect){
  char ch = UDR0;
  if(ch == '\n'){
    if(maxLength){
      data_length = 30;
    }
    else{
      data_length = trigger;
    }    
  }
  else{
    buf[trigger] = ch;
    data_length = 0;
  }
  trigger ++;
  if(trigger >= buf_length){
    trigger = 0;
    maxLength  = true;
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
  if(data_length != 0){    
    for(char i = 0 ; i <= data_length - 1 ; i = i + 1){      
      for(char j = i + 1 ; j <= data_length; j = j + 1){
        char state01 = 0;
        char state02 = 0;
        if( (buf[i]>=65) && (buf[i] <=90) ){
          state01 = 3;
        }
        else if( (buf[i]>=48) && (buf[i] <=57) ){
          state01 = 2;
        }
        else if( (buf[i]>=97) && (buf[i] <=122) ){
          state01 = 1;
        }
        
        if( (buf[j]>=65) && (buf[j] <=90) ){
          state02 = 3;
        }
        else if( (buf[j]>=48) && (buf[j] <=57) ){
          state02 = 2;
        }
        else if( (buf[j]>=97) && (buf[j] <=122) ){
          state02 = 1;
        }

        if(state01 == state02){
          if(buf[i] < buf[j]){
            char tool = buf[i];
            buf[i] = buf[j];
            buf[j] = tool;
          }
        }
        else if(state01 < state02){
          char tool = buf[i];
          buf[i] = buf[j];
          buf[j] = tool;
        }
      }
    }
    for(char idx = 0 ; idx < data_length ; idx++){
      UART_Putch(buf[idx]);
    }
    UART_Putch('\n');
    data_length = 0;
    trigger = 0;
    maxLength = false;
  }  
}
