#include<EEPROM.h>

struct Identify{
  char Work[20];
  char Name[20];
};

int address = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Identify who;
  EEPROM.get(address, who);
  // 해당 주소에 저장되어있는 구조체 Identify 정보를를
  // who에 덮어씌운다.
  for(int i = 0 ; i < sizeof(who.Work)/sizeof(char) ; i++){
    Serial.print(who.Work[i]);
  }
  Serial.println();
  for(int i = 0 ; i < sizeof(who.Name)/sizeof(char);i++){
    Serial.print(who.Name[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
