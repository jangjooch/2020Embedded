void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  AND7408(0,0);
  delay(1000);

  AND7408(1,0);
  delay(1000);

  AND7408(0,1);
  delay(1000);

  AND7408(1,1);
  delay(1000);
//---------------------------
  NAND7400(0,0);
  delay(1000);

  NAND7400(1,0);
  delay(1000);

  NAND7400(0,1);
  delay(1000);

  NAND7400(1,1);
  delay(1000);
  //---------------------------
  XORchip(0,0);
  delay(1000);

  XORchip(1,0);
  delay(1000);

  XORchip(0,1);
  delay(1000);

  XORchip(1,1);
  delay(1000);
}

// NAND
void NAND7400(int a, int b){
  if(a){
    digitalWrite(2,HIGH);
  }
  else{
    digitalWrite(2,LOW);
  }
  if(b){
    digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(3,LOW);
  }
    
  if(!(a & b)){
    digitalWrite(4,HIGH);
  }
  else{
    digitalWrite(4,LOW);
  }
}
//AND
void AND7408(int a, int b){
  if(a){
    digitalWrite(2,HIGH);
  }
  else{
    digitalWrite(2,LOW);
  }
  if(b){
    digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(3,LOW);
  }
    
  if(a & b){
    digitalWrite(4,HIGH);
  }
  else{
    digitalWrite(4,LOW);
  }
}

//XOR
void XORchip(int a, int b){
  if(a){
    digitalWrite(2,HIGH);
  }
  else{
    digitalWrite(2,LOW);
  }
  if(b){
    digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(3,LOW);
  }
    
  if(a ^ b){
    digitalWrite(4,HIGH);
  }
  else{
    digitalWrite(4,LOW);
  }
}
