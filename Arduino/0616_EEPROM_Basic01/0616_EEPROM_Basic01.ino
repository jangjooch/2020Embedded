
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start");
  for(int i = 0 ; i < 10 ; i++){
    EEPROM_Write(i, 'c');
    char ch = EEPROM_Read(i);
    if( ch != 'c' ){      
      Serial.print("EEPROM Error : ");
      Serial.println(ch);
    }
    else{
      Serial.println(ch);
    }
  }
  Serial.println("DONE");
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
