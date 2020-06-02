void setup() {
  // put your setup code here, to run once:
  DDRC = 0xFF;
  // 1 출력, 0 입력
  // 전부 출력으로 설정한다,
  PORTC = 0x55;
  // 포트 C의 0,2,4,6 번 비트에 HIGH를 출력한다.
  DDRE = 0x00;
  // PORTE의 모든 비트를 입력으로 설정
  
  PORTC = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char sw;
  
  while(true){
    sw = PINE & 0x10;
    // DDRE 4 번째 비트의 입력을 읽는다.
    if(sw != 0){
      // Active LOW이기 때문에
      // 버튼을 눌렀다면 작동하도록 한다.
      PORTC = 0xFF;
    }
    else{
      PORTC = 0x00;
    }
  }
}
