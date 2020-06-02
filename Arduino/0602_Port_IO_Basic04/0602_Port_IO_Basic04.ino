
int num;
int state = 0;
void setup() {
  // put your setup code here, to run once
  DDRD = 0xFF;
  num = 0x01;
  // Serial 통신을 통해 모니터로 확인하려 한다면 0,1번핀을
  // 사용할 수 없다.
  //Serial.begin(9600);
}

void loop() {
  if(num >= 0x80){
    state = 1;    
  }
  else if(num <= 0x01){
    state = 0;
  }
  if(state == 1){
    num = num >> 1;
  }
  else{
    num = num << 1;
  }
  
  PORTD = ~num;
  //Serial.println();
  delay(1000);  
}
