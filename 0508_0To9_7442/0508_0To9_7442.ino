void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT); 
  
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
  int d = digitalRead(5);

  
  Chip7442(a, b, c, d);
  /*

  if(a){
    digitalWrite(6,HIGH);
  }
  else{
    digitalWrite(6,LOW);
  }
   if(b){
    digitalWrite(7,HIGH);
  }
  else{
    digitalWrite(7,LOW);
  }
   if(c){
    digitalWrite(8,HIGH);
  }
  else{
    digitalWrite(8,LOW);
  }
   if(d){
    digitalWrite(9,HIGH);
  }
  else{
    digitalWrite(9,LOW);
  }
  
   */
  
}

void Chip7442(int a, int b, int c, int d){
  // 0
  if(!((!a) & (!b) & (!c) & (!d))){
    digitalWrite(6,HIGH);
  }
  else{
    digitalWrite(6,LOW);
  }
  
  // 1
  if(!((a) & (!b) & (!c) & (!d))){
    digitalWrite(7,HIGH);
  }
  else{
    digitalWrite(7,LOW);
  }
  
  // 2
  if(!((!a) & (b) & (!c) & (!d))){
    digitalWrite(8,HIGH);
  }
  else{
    digitalWrite(8,LOW);
  }
  
  // 3
  if(!((a) & (b) & (!c) & (!d))){
    digitalWrite(9,HIGH);
  }
  else{
    digitalWrite(9,LOW);
  }
  
  // 4
  if(!((!a) & (!b) & (c) & (!d))){
    digitalWrite(10,HIGH);
  }
  else{
    digitalWrite(10,LOW);
  }

  // 5
  if(!((a) & (!b) & (c) & (!d))){
    digitalWrite(11,HIGH);
  }
  else{
    digitalWrite(11,LOW);
  }

  // 6
  if(!((!a) & (b) & (c) & (!d))){
    digitalWrite(12,HIGH);
  }
  else{
    digitalWrite(12,LOW);
  }

  // 7
  if(!((a) & (b) & (c) & (!d))){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  /*
  
  // 8
  if(!((!a) & (!b) & (!c) & (d))){
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
  }
  else{
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }

  // 9
  if(!((a) & (!b) & (!c) & (d))){
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
  }
  else{
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
  */
  
  
}
