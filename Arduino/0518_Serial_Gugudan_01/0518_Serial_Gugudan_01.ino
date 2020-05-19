void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bool state = true;
  while(state){
    Serial.println("Input Num. if over 9 will End");
    int num = 0;
    bool numState = true;
    while(numState){
      if(Serial.available()){
        num = Serial.parseInt();
        numState = false;
      }
    }
    
    if(num > 9){
      Serial.println("PROGRAM END");
      state = false;
    }
    else{
      for(int i = 0; i < 10 ; i ++){        
        Serial.print(num);
        Serial.print(" * ");        
        Serial.print(i);
        Serial.print(" = ");
        int result = num * i;
        Serial.println(result);
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
