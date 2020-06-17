char data[100];
int dataLength = 1;
int readLength = 0;
int TriggerIn = 0;


void setup() {
  // put your setup code here, to run once:
  UCSR0B = 0x98;
  UBRR0 = 103;
  SREG |= 0x80;

  FILE *fp;
  fp = fdevopen((void *)UART_Putch, 0);
  printf("START");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(TriggerIn == 1){
    tags();
    putch();
    TriggerIn = 0;
  }
}

void tags(){
  printf("TAG");
  char *temp;
  temp = strcpy(data,strlen(data));
  char *label;
  label = strstr(temp, "[");
  UART_Puts(label);
  
}
void UART_Puts(char arr[]){
  int i = 0;
  while(arr[i] != 0){
    UART_Putch(arr[i]);
    i++;
  }  
}
void UART_Putch(char ch)
{
    while(!(UCSR0A & 0x20));
    UDR0 = ch;
}
void putch(){
  UCSR0B |= 0x20;
}

ISR(USART_UDRE_vect){  
  char ch = data[readLength];  
  UDR0 = ch;
  if(dataLength == readLength){
    UCSR0B &= 0x20;
  }
  else{
    readLength++;
  }
}
ISR(USART_RX_vect){
  char ch = UDR0;
  //printf(ch);  
  if(ch == '\n'){
    TriggerIn = 1;
  }
  else{
    data[dataLength] = ch;
    dataLength++;
  }
}
