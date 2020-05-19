#include<EEPROM.h>


int address = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  char string[] = "Korea Polytech";
  char shj[] = "Sang Hyeok Jang";

  for(int i = 0 ; i < sizeof(string)/sizeof(char) ; i++){
    EEPROM.write(address, string[i]);
    address++;
  }
  EEPROM.write(address, 67);
  // #에 해당하는 아스키 코드
  address++;  
  for(int i = 0 ; i < sizeof(shj)/sizeof(char) ; i++){
    EEPROM.write(address, shj[i]);
    address++;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
