unsigned char led;

void setup() {
  // put your setup code here, to run once:
  led = 0x01;
  
  DDRB = 0x0F;
  DDRC = 0x0F;

  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
