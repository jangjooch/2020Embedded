void setup() {
  // put your setup code here, to run once:
  // selector
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);

  pinMode(6, OUTPUT); // 0
  pinMode(7, OUTPUT); // 1
  pinMode(8, OUTPUT); // 2
  pinMode(9, OUTPUT); // 3
  pinMode(10, OUTPUT);// 4
  pinMode(11, OUTPUT);// 5
  pinMode(12, OUTPUT);// 6
  pinMode(13, OUTPUT);// 7
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = digitalRead(2);
  int b = digitalRead(3);
  int c = digitalRead(4);

  Mutiplexer74138(a , b, c);
}

void Mutiplexer74138(int a, int b, int c){
  if( !( (!a) & (!b) & (!c) ) ){
    digitalWrite(6,HIGH);
  }
  else{
    digitalWrite(6,LOW);
  }
  
  if( !( (a) & (!b) & (!c) ) ){
    digitalWrite(7,HIGH);
  }
  else{
    digitalWrite(7,LOW);
  }
  
  if( !( (!a) & (b) & (!c) ) ){
    digitalWrite(8,HIGH);
  }
  else{
    digitalWrite(8,LOW);
  }

  if( !( (a) & (b) & (!c) ) ){
    digitalWrite(9,HIGH);
  }
  else{
    digitalWrite(9,LOW);
  }

  if( !( (!a) & (!b) & (c) ) ){
    digitalWrite(10,HIGH);
  }
  else{
    digitalWrite(10,LOW);
  }

  if( !( (a) & (!b) & (c) ) ){
    digitalWrite(11,HIGH);
  }
  else{
    digitalWrite(11,LOW);
  }
  
  if( !( (!a) & (b) & (c) ) ){
    digitalWrite(12,HIGH);
  }
  else{
    digitalWrite(12,LOW);
  }

  if( !( (a) & (b) & (c) ) ){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  
}
