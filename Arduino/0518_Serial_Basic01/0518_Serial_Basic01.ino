void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Testing");

  // write
  char testarry[4] = {'t','e','s','t'};
  Serial.write(testarry,4);
  Serial.write(33);
  Serial.write("DAM");
  Serial.println();

  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available()){
    char data[50];
    byte dataLength = Serial.readBytes(data, 50);
    Serial.print("data Length : ");
    Serial.println(dataLength);
    Serial.write(data, dataLength);
    Serial.println();
    //float inputData = Serial.parseFloat();    
    //int inputData = Serial.parseInt();    
    //int inputData = Serial.read();
    //Serial.println(inputData);
    /*    
    if(inputData == '1'){
      Serial.println(1);
    }
    else{
      Serial.println("word");
    }
    */
    
  }
}
