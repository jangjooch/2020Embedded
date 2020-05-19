#include<EEPROM.h>

int address = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  for(int i = 0 ; i < EEPROM.length() ; i++){
    EEPROM.write(i, 0);
  }
  digitalWrite(13, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
 
}
