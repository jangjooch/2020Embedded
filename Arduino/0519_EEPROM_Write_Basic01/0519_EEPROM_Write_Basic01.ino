#include <EEPROM.h>

int value = 0x00;
int address = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){
    ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  EEPROM.write(address, value);
  value++;
  address++;
  if(value > 255){
    value = 0;
  }
  delay(500);
}