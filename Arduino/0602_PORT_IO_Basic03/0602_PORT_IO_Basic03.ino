void setup() {
  // put your setup code here, to run once
  DDRD = 0xFF;
  DDRB = 0x00; //1111 1101
  // PORTB 1번핀만 INPUT;  
}

void loop() {
  char sw1 = (PINB & 0x02);
  if(sw1 != 0){
    PORTD = 0xFF;
  }
  else{
    PORTD = 0x00;
  }
  
}
