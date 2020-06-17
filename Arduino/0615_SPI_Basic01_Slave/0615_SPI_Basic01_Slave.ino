void setup() {
  // put your setup code here, to run once:
  SPCR = 0b01000011;
  // SPI Enable
  // 
  SPSR = 0x00;
  DDRB = 0b00010000;
  // SS SCK MOSI Input
  // MISO OUTPUT
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(byte i = 0; i<255 ; i++){
    SPDR = i;
    // Master에 데이터 전송
    while(!(SPSR & 0x80)){
      // 데이터 전송 대기
    }
    byte dataGet = SPDR;
    Serial.println(dataGet, HEX);
        
  }
}
