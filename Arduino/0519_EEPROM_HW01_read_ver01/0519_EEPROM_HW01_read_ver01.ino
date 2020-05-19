#include<EEPROM.h>

int address = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0 ; i < 50 ; i++){
    
    int value = EEPROM.read(address);
    Serial.write(value);
    if(value == 67){
      Serial.println();  
    }    
    address++;
    delay(500);
  }
  
}
