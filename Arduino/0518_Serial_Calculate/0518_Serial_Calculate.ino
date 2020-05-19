void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bool state = true;
  while(state){
    Serial.println("1. +\n");
    Serial.println("2. -\n");
    Serial.println("3. *\n");
    Serial.println("4. /\n");
    Serial.println("5. END\n");
    Serial.println("Type what to use : ");
    int select = 0;
    select = Serial.parseInt();
    char tool = ' ';
    
    if(select == 1){
      tool = '+';
    }
    else if(select == 2){
      tool = '-';
    }
    else if(select == 3){
      tool = '*';
    }
    else if(select == 4){
      tool = '/';
    }
    else{
      Serial.println("PROGRAM END");
      state = false;
      break;
    }

    Serial.println("Input Data");
    char num01[10];
    byte num01Length = Serial.readBytesUntil(' ', num01, 10);
    char num02[10];
    byte num02Length = Serial.readBytes(num02,10);
    Serial.print(num01);
    Serial.print(num02);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
}
