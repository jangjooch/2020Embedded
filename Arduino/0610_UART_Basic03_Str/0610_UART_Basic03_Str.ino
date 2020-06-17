char data[100]; // 받은 데이터 저장할 공간
int dataLength = 0;
int readLength = 0;
int TriggerIn = 0; // \n 오면 받은 데이터 처리후 보내는 Trigger

char tags[100] = {0, };
int tagsidx = 0;
char copy[100] = { 0, };
int copyidx = 0;
char state[100] = { 0, };

int tagstate = 0;
int currstate = 0;

void setup() {
  // put your setup code here, to run once:
    UCSR0B = 0x98;
    UBRR0 = 103;
    SREG |= 0x80;
    
    FILE *fp;
    fp = fdevopen((void *)UART_Putch, 0);
    printf("START\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(TriggerIn == 1){
    tagsSet();
    stateSet();
    sendData();
    TriggerIn = 0;    
  }
}

void tagsSet(){
  strcpy(copy, data);
  char *Stags;
  char *Etags;  
  Stags = strchr(copy, '[');
  Etags = strchr(copy, ']');
  // 태그만 뽑아내기
  while (Stags != NULL) {
    int sidx = Stags - copy;
    int eidx = Etags - copy;
    char tagGet[10] = { 0, };
    int tagGetidx = 0;
    for (int i = sidx + 1; i < eidx; i++) {
      tagGet[tagGetidx++] = copy[i];
    }    
    char *found;
    found = strstr(tags, tagGet);
    if (found == NULL) {
      tags[tagsidx++] = tagstate + '0';
      tagstate++;
      for (int i = sidx + 1; i < eidx; i++) {       
        tags[tagsidx++] = copy[i];
      }
    }
    Stags = strchr(Stags + 1, '[');
    Etags = strchr(Etags + 1, ']');
  }
}

void stateSet(){  
  char *tagstart;
  char *tagend;
  char *nexttag;
  tagstart = strchr(copy, '[');
  tagend = strchr(copy, ']');
  nexttag = strchr(tagend + 1, '[');

  while (tagstart != NULL) {
    
    int sidx = tagstart - copy;
    int eidx = tagend - copy;
    
    // 태그 가져오기
    char tagGet[10] = { 0, };
    int tagGetidx = 0;
    for (int i = sidx + 1; i < eidx; i++) {
      tagGet[tagGetidx++] = copy[i];      
    }

    char *found;
    found = strstr(tags, tagGet);

    // 찾은 태그의 바로 앞의 인덱스 추출
    int foundidx = found - tags - 1; 

    if (nexttag != NULL) {
      int scon = tagend - copy;
      int econ = nexttag - copy;
      for (int i = scon + 1; i < econ; i++) {
        state[i] = tags[foundidx];
      }
    }
    else {
      int scon = tagend - copy;
      for (int i = scon + 1; i < strlen(copy); i++) {
        state[i] = tags[foundidx];
      }
    }
    tagstart = strchr(tagstart + 1, '[');
    tagend = strchr(tagend + 1, ']');
    if (tagend != NULL) {
      nexttag = strchr(tagend + 1, '[');
    }
  }
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

void sendData(){
  for(int i = 0 ; i < tagstate ; i++){
    for(int j = 0 ; j < strlen(copy) ; j++){
      if(i == state[j] - '0'){
        char ch = copy[j];
        UART_Putch(ch);
      }
    }
    UART_Putch('\n');
  }
}
// UDRE에 데이터 쌓이면 데이터 보내기 작동 Interrupt Enable
void putch(){
  UCSR0B |= 0x20;
}
// 읽은 데이터가 보내는 데이터가 같다면 Interrupt Disable
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

// 받았을때 작동하는 Interrupt
// \n 나오기 전까지 data에 쌓는다.
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

int testLen(char arr[]){
  return strlen(arr);
}
