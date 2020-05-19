#include <EEPROM.h>

int address = 0;
byte value;

void setup() {
  // initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; 
    // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  // read a byte from the current address of the EEPROM
  value = EEPROM.read(address);
  // EEPROM에서 해당 address 값을 읽어 int에 저장
  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.print("    ");
  Serial.print(value, HEX);
  Serial.println();

  address = address + 1;
  if (address == EEPROM.length()) {
    address = 0;
  }
  delay(500);
}
