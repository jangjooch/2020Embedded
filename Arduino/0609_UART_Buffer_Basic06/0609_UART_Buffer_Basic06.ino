#define BUF_NUM 16
#define RX_BUF_NUM  100
#define TX_BUF_NUM  100
char buf[BUF_NUM], rxBuf[RX_BUF_NUM];
char txBuf[TX_BUF_NUM];
char head, tail;
bool bFull, bEmpty;
int buf_index, tx_len, tx_index;

char RxAvailable();
char UART_Getchar();
void UART_Putch(char ch);
void Sorting(void);

void setup() {
    UCSR0B = 0x98;
    UBRR0 = 103;
    SREG |= 0x80;

    head = tail = 0;
    bFull = false;
    bEmpty = true;
    buf_index = 0;

    FILE *fp;
    fp = fdevopen((void *)UART_Putch, 0);
    printf("test %d", UBRR0);
    //UBRR0;
}

void loop() {
    if(RxAvailable() > 0){
        char ch;
        ch = UART_Getchar();
        UART_Putch(ch);
        if(buf_index < RX_BUF_NUM){
            if(ch != '\n')
                rxBuf[buf_index++] = ch;
            else {
                Sorting();               
                buf_index = 0;
            }       
        }        
    }
}

void Sorting(void)
{
    char temp;
    char temp_buf[RX_BUF_NUM];
    char i, j;

    for(i=0; i<buf_index-1; i++){
        for(j=0; j<buf_index-i-1; j++){
            if(rxBuf[j] < rxBuf[j+1]){
                temp = rxBuf[j+1];
                rxBuf[j+1] = rxBuf[j];
                rxBuf[j] = temp;
            }
        }
    }

    j = 0;
    for(i=0; i<buf_index; i++){
        if(rxBuf[i] >='A' && rxBuf[i] <= 'Z')
            temp_buf[j++] = rxBuf[i];
    }
    for(i=0; i<buf_index; i++){
        if(rxBuf[i] >='0' && rxBuf[i] <= '9')
            temp_buf[j++] = rxBuf[i];
    }
    for(i=0; i<buf_index; i++){
        if(rxBuf[i] >='a' && rxBuf[i] <= 'z')
            temp_buf[j++] = rxBuf[i];
    }
    
    SendBuf(temp_buf, buf_index);
}

void SendBuf(char buf[], int send_num)
{
  tx_len = send_num;
  memcpy(txBuf, buf, send_num);
  //for(int i=0; i<send_num; i++) txBuf[i] = buf[i];
  tx_index = 0;
  UCSR0B |= 0x20; // UDRE Interrupt Enable....
}

ISR(USART_UDRE_vect)
{
  UDR0 = txBuf[tx_index];
  if(++tx_index == tx_len) UCSR0B &= 0xDF;
}

void UART_Putch(char ch)
{
    while(!(UCSR0A & 0x20));
    UDR0 = ch;
}

char UART_Getchar()
{
    char ch;

    if(bEmpty == false){
        ch = buf[tail];
        tail++;
        if(tail == BUF_NUM) tail = 0;

        if(tail == head) bEmpty = true;

        bFull = false;
        return ch;
    }
    else return 0;
    
}

char RxAvailable()
{
    if(head > tail) return (head - tail);
    else if(tail > head) return (BUF_NUM - tail + head);
    else return 0;
}

ISR(USART_RX_vect)
{
    char ch;
    ch = UDR0;

    if(bFull == false){
        buf[head] = ch;
    
        head++;  
        bEmpty = false;
        if(head == BUF_NUM) 
            head = 0;
        if(head == tail && bFull == false)  bFull = true;
    }
}
