void setup() {
  // put your setup code here, to run once:
  SPCR = 0b01010011;
  // SPI Enable
  // Data Trans MSB
  // Master Set
  // clk = /128
  // CPOL CPHA 0 0  -> Leading : Rising,  Traing : Falling

  SPSR = 0x00;  
  DDRB = 0b00101100;
  // SCK MOSI SS   = OUTPUT
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(byte i = 0 ; i<255 ; i++){
    PORTB &= 0xFB;
    // SS LOW 설정
    // Slave Select LOW 즉 평상시 모든 Slave는
    // HIGH로 설정되어 있기때문에 LOW를 주어 데이터를
    // 보내겠다고 신호를 주는 것이다.
    // 1111 1011
    // 1111 1011 출력 SCK변환 X
    SPDR = i;    
    while(!(SPSR &= 0x80)){
      // HIGH -> LOW변환이기때문에
      // 데이터 전송이 완료되었을 때 1 Set
      // CPOL CPHA가 00됨으로서 HIGH -> LOW가 될때 데이터를 썻다는 의미이니
      // 정상적으로 데이터가 전송되었다는 것을 의미
    }
    byte dataGet = SPDR;
    Serial.println(dataGet, HEX);
    PORTB |= 0x04;
    // 데이터를 보내었으니 다시 HIGH로 설정하여 잠그는 것이다.
    delay(10);
  }
}
