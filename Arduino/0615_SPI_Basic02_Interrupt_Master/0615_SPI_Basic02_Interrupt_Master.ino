void setup() {
  // put your setup code here, to run once:
  SPCR = 0b11010011;
  // SPI Interrupt Enable
  // Master Set
  SPSR = 0x00;
  DDRB = 0b00101100;
  // SCK MOSI SS OUTPUT
  Serial.begin(9600);
}

char Trigger = 0;
byte dataGet = 0;
byte sendData = 1;
void loop() {
  // put your main code here, to run repeatedly:
  if(Trigger){
    PORTB &= 0xFB;
    // SS LOW 설정
    // 데이터를 보내기 위하여 HIGH로 설정된 Slave Select를
    // LOW로 설정하여 데이터를 보내겠다고 암시한다.
    // 아래는 Miss understanding
    // HIGH -> LOW로 설정해줌으로서 강제 하강엣지 생성
    // 데이터를 쓰도록 한다.
    sendData++;
    SPDR = sendData;
  }
  else{
    Serial.println(dataGet, HEX);
    Trigger = 1;
    PORTB |= 0x04;
    // SS HIGH 설정
    // 데이터를 보내었으니 다시 HIGH로 설정하여 잠근다.
    // 아래는 Miss UnderStanding이다.
    // 데이터를 읽었으니 다음에는 Write를 해야함으로    
    // LOW -> HIGH로 만든것이니 강제 상승엣지 생성
  }
}

// 전송 완료 Interrupt
ISR(SPI_STC_vect){
  dataGet = SPDR;
  Trigger = 0;
}
