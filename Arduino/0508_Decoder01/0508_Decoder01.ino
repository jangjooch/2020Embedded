
void setup() {
  // put your setup code here, to run once:
 pinMode(2, INPUT);
 pinMode(3, INPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = digitalRead(2);
  int b = digitalRead(3);
  Decoder2By4(a, b);
}

void Decoder2By4(int a, int b){
  if((!a) * (!b)){
    digitalWrite(4,HIGH);
  }
  else{
    digitalWrite(4,LOW);
  }

  if((a) * (!b)){
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }
  
  if((!a) * (b)){
    digitalWrite(6,HIGH);
  }
  else{
    digitalWrite(6,LOW);
  }
  
  if((a) * (b)){
    digitalWrite(7,HIGH);
  }
  else{
    digitalWrite(7,LOW);
  } 
}
