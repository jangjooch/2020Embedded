

void setup() {
  // put your setup code here, to run once:
  int address = 0;
  unsigned char RealTime_Set = 0;
  unsigned char hour10 = 1;
  unsigned char hour1 = 1;
  unsigned char min10 = 4;
  unsigned char min1 = 5;
  Serial.begin(9600);

  EEPROM_Write(address, RealTime_Set); 

  address += sizeof(RealTime_Set);
  EEPROM_Write(address, hour10);
  int ch = EEPROM_Read(address);
  Serial.println(ch);
  
  address += sizeof(hour10);
  EEPROM_Write(address, hour1);
  ch = EEPROM_Read(address);
  Serial.println(ch);
  
  address += sizeof(hour1);
  EEPROM_Write(address, min10);
  ch = EEPROM_Read(address);
  Serial.println(ch);
  
  address += sizeof(min10);
  EEPROM_Write(address, min1);
  ch = EEPROM_Read(address);
  Serial.println(ch);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void EEPROM_Write(int address, char data){
  //Serial.println("Write Start");
  while((EECR & 0x02) ){
    // EEWE 0인지 확인하도록 delay
  }
  EEAR = address;
  EEDR = data;
  EECR |= 0x04; // EEMWE 1 Set
  EECR |= 0x02; // EEWE 1 Set
  // 동시에 하면 안된다. EEMWE가 Set되어야
  // Write하겠다는 암시를 하는 것이다.
  // 이후 Write가 완료되면 HW적으로 0 Clear 된다.
  //Serial.println("Write Done");
}

char EEPROM_Read(int address){
  //Serial.println("Read Start");
  while((EECR & 0x02) ){
    // EEWE 0인지 확인하도록 delay
  }
  EEAR = address;
  EECR |= 0x01; // EERE 1 Set
  char data = EEDR;
  //Serial.println("Read Done");
  return data;  
}
