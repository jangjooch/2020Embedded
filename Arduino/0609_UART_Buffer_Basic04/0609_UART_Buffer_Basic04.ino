#define BUF_NUM 16
char buf[16];
char head, tail;
bool bFull, bEmpty;



char sorted[30];
char Upper[10];
char Lower[10];
char Nums[10];

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
        //UART_Putch('A');
        //UART_Putch('\n');
        char ch;
        ch = UART_Getchar();
        if(ch >= 'A' && ch <= 'Z'){
          //UART_Putch('U');          
          upper++;
          char idx = upper;
          //UART_Putch(idx + '0');
          //UART_Putch('\n');
          Upper[upper - 1] = ch;
        }
        else if(ch >= 'a' && ch <= 'z'){
          //UART_Putch('L');          
          lower++;
          char idx = lower;
          //UART_Putch(idx + '0');
          //UART_Putch('\n');
          Lower[lower - 1] = ch;
        }
        else if( ch >= '0' && ch <= '9'){
          //UART_Putch('N');
          nums++;
          char idx = nums;
          //UART_Putch(idx + '0');
          //UART_Putch('\n');          
          Nums[nums - 1] = ch;
        }
        else{
          if(ch == '\n'){
            trigger = 1;
          }
        }
        //trigger = 1;
        //UART_Putch(ch);
    }
    else if(RxAvailable() == 0 && trigger == 1){
      //UART_Putch('S');
//      UART_Putch('\n');
//      UART_Putch(upper + '0');
//      UART_Putch(Upper[0]);
//      UART_Putch('\n');
//      UART_Putch(lower + '0');
//      UART_Putch(Lower[0]);
//      UART_Putch('\n');
//      UART_Putch(nums + '0');
//      UART_Putch(Nums[0]);
//      UART_Putch('\n');
      //Upper[upper] = 0;
      //Lower[lower] = 0;
      //Nums[nums] = 0;
      //sorted = (char *)malloc(sizeof(char) * (upper + lower + nums));
      int testL = sizeof(Upper) / sizeof(char);
      sorting(Upper, testL);
      testL = sizeof(Lower) / sizeof(char);
      sorting(Lower, testL);
      testL = sizeof(Nums) / sizeof(char);
      sorting(Nums, testL);      
      UART_Puts(Upper);
      UART_Puts(Nums);
      UART_Puts(Lower);
      //UART_Putch('E');
      UART_Putch('\n');
      trigger = 0;
    }
}

void sorting(char arr01[], int leng){  
  for (int i = 0; i < leng - 1; i++) {
    for (int j = i + 1; j < leng; j++) {
      if (arr01[i] < arr01[j]) {
        char temp = arr01[i];
        arr01[i] = arr01[j];
        arr01[j] = temp;
      }
    }   
  }
}

void UART_Puts(char arr[]){
  //UART_Putch('S');
  //UART_Putch('\n');  
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
