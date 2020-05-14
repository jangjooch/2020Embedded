void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, INPUT); 
  Serial.begin(9600); 
  analogWrite(9, 127);
  tone(5, 1000);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long a = pulseIn(3, HIGH);
  Serial.println(a);
  int b = analogRead(3);
  if(b){
    digitalWrite(2, digitalRead(2)^1);  
  }  
}
