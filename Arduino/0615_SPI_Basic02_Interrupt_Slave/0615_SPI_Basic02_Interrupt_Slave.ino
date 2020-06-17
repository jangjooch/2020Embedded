void setup() {
  // put your setup code here, to run once:
  SPCR = 0b11000011;
  // SPI Interrupt Enable;
  // SPI Enable
  SPSR = 0x00;
  DDRB = 0b00010000;
  // SS SCK MOSI Input
  // MISO OUTPUT
  Serial.begin(9600);
}

char Trigger = 0;
byte dataGet = 0;
byte sendData = 1;
void loop() {
  // put your main code here, to run repeatedly:
  if(Trigger){
    sendData++;
    SPDR = sendData;
  }
  else{
    Serial.println(dataGet, HEX);
    Trigger = 1;
  }  
}

// 전송 완료 Interrupt
ISR(SPI_STC_vect){
  dataGet = SPDR;
  Trigger = 0;
}
