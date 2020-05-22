#include <EEPROM.h>

struct Time{
  int state;
  int hour;
  int mini;
  int sec;
  int music;
};


void setup() {
  // put your setup code here, to run once:
  Time timePut = {
    0,
    11,
    15,
    45,
    0
  };
  EEPROM.put(0, timePut);
}

void loop() {
  // put your main code here, to run repeatedly:

}
