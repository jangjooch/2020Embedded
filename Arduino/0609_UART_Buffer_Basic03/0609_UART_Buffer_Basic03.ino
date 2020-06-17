#define BUF_NUM 16
char buf[16];
char head, tail;
bool bFull, bEmpty;



char *sorted;
char *Upper;
char *Lower;
char *Nums;

int upper = 0;
int lower = 0;
int nums = 0;

int trigger = 0;

void setup() {    
    UCSR0B = 0x98;
    UBRR0 = 103;
    SREG |= 0x80;

    head = tail = 0;
    bFull = false;
    bEmpty = true;
}

void loop() {
    
    if(RxAvailable() > 0){
        UART_Putch('A');
        UART_Putch('\n');
        char ch;
        ch = UART_Getchar();
        if(ch >= 'A' && ch <= 'Z'){
          UART_Putch('U');
          
          upper++;

          char idx = upper;
          UART_Putch(idx + '0');
          UART_Putch('\n');
          
          Upper = (char *)malloc(sizeof(char) * upper);
          Upper[upper - 1] = ch;
          UART_Putch(Upper[0]);
        }
        else if(ch >= 'a' && ch <= 'z'){
          UART_Putch('L');          
          lower++;

          char idx = lower;
          UART_Putch(idx + '0');
          UART_Putch('\n');
          
          Lower = (char *)malloc(sizeof(char) * lower);
          Lower[lower - 1] = ch;
        }
        else if( ch >= '0' && ch <= '9'){
          UART_Putch('N');
          nums++;

          char idx = nums;
          UART_Putch(idx + '0');
          UART_Putch('\n');
          
          Nums = (char *)malloc(sizeof(char) * nums);
          Nums[nums - 1] = ch;
        }
        else{
          
        }
        trigger = 1;
        //UART_Putch(ch);
    }
    else if(RxAvailable() == 0 && trigger == 1){
      UART_Putch('T');
      UART_Putch('\n');
      UART_Putch(upper + '0');
      UART_Putch(Upper[0]);
      UART_Putch('\n');
      UART_Putch(lower + '0');
      UART_Putch(Lower[0]);
      UART_Putch('\n');
      UART_Putch(nums + '0');
      UART_Putch(Nums[0]);
      UART_Putch('\n');
      //Upper[upper] = 0;
      //Lower[lower] = 0;
      //Nums[nums] = 0;
      //sorted = (char *)malloc(sizeof(char) * (upper + lower + nums));      
      UART_Puts(Upper);
      UART_Putch('\n');
      UART_Puts(Lower);
      UART_Putch('\n');
      UART_Puts(Nums);
      UART_Putch('\n');
      trigger = 0;
    }
}

void UART_Puts(char arr[]){
  UART_Putch('S');
  UART_Putch(arr[0]);
  UART_Putch('\n');  
  int i = 0;
  while(arr[i] != 0){
    UART_Putch(arr[i]);
    i++;
  }
  UART_Putch('\n');  
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
    if(head > tail)return (head - tail);
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
