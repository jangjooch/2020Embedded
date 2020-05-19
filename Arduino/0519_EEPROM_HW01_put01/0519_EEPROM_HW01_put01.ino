#include<EEPROM.h>

struct Identify{
  char Work[20];
  char Name[20];
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int address = 0;
  
  Identify shj = {
    "Anyang GanAk Str",
    "Sang Hyeok Jang"
  };
  EEPROM.put(address, shj);
}

void loop() {
  // put your main code here, to run repeatedly:

}
