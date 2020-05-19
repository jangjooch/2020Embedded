void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  int ascii[3][21] = { 0, };
  int asciiStack = 32;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 21; j++) {
      ascii[i][j] = asciiStack;
      asciiStack++;
    }
    if (i == 0)
      asciiStack = 64;
    if (i == 1)
      asciiStack = 92;
  }
  Serial.print("=====================================================================================\n");
  Serial.print("DEX\tHEX\tCHAR\t\tDEX\tHEX\tCHAR\t\tDEX\tHEX\tCHAR\n");
  Serial.print("=====================================================================================\n");
  for(int i = 0 ; i < 21 ; i++){
    Serial.print(ascii[0][i]);
    Serial.print("\t");
    Serial.print(ascii[0][i], HEX);
    Serial.print("\t");
    Serial.write(ascii[0][i]);
    Serial.print("\t\t");
    
    Serial.print(ascii[1][i]);
    Serial.print("\t");
    Serial.print(ascii[1][i], HEX);
    Serial.print("\t");
    Serial.write(ascii[1][i]);
    Serial.print("\t\t");
    
    Serial.print(ascii[2][i]);
    Serial.print("\t");
    Serial.print(ascii[2][i], HEX);
    Serial.print("\t");
    Serial.write(ascii[2][i]);
    Serial.print("\n");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
