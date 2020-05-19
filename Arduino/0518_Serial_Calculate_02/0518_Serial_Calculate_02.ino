void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bool outterState = true;
  while(outterState){
    Serial.println("1. +");
    Serial.println("2. -");
    Serial.println("3. *");
    Serial.println("4. /");
    Serial.println("5. END");
    Serial.println("Type what to use : ");
    int select = 0;
    bool toolState = true;
    while(toolState){
      if(Serial.available()){
        select = Serial.parseInt();
        Serial.println(select);
        toolState = false;
      }
    }
    if(select == 5){
      Serial.println("PROGRAM END");
      outterState = false;
    }
    else{
      Serial.println("Input 2 Num");
      char numState = true;
      int num1;
      int num2;
      while(numState){
        if(Serial.available()){
          char num01[10];
          byte num01Length = Serial.readBytesUntil(' ', num01, 10);
          char num02[10];
          byte num02Length = Serial.readBytes(num02,10);
          numState = false;
          //Serial.write(num01, num01Length);
          //Serial.write(num02, num02Length);
          num1 = atoi(num01);
          num2 = atoi(num02);
        }
      }
      //Serial.print(num1);
      //Serial.print(num2);
      // 나누기는 결과가 실수여야 되니까
      // 이미 5번의 경우는 배제했기때문에 무시
      if(select == 4){
        float fnum1 = num1;
        float fnum2 = num2;
        float result = fnum1 / fnum2;
        Serial.print(num1);
        Serial.print(" / ");
        Serial.print(num2);
        Serial.print(" = ");
        Serial.println(result, 5);
        // 소수점 3 까지 출력하도록
      }
      else{
        int result = 0;
        if(select == 1){
          result = num1 + num2;
          Serial.print(num1);
          Serial.print(" + ");
          Serial.print(num2);
          Serial.print(" = ");
          Serial.println(result);
        }
        else if(select == 2){
          result = num1 - num2;
          Serial.print(num1);
          Serial.print(" - ");
          Serial.print(num2);
          Serial.print(" = ");
          Serial.println(result);
        }
        else if(select ==3){
          result = num1 * num2;
          Serial.print(num1);
          Serial.print(" * ");
          Serial.print(num2);
          Serial.print(" = ");
          Serial.println(result);
        }
      }
      Serial.println();
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.flush();
  Serial.end();
}
