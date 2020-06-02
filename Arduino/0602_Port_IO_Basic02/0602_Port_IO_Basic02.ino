
char num;
void setup() {
  // put your setup code here, to run once
  DDRD = 0xFF;
  num = 0x01;
  // Serial 통신을 통해 모니터로 확인하려 한다면 0,1번핀을
  // 사용할 수 없다.
}

void loop() {
  PORTD = ~num;
  if(num == 0x80){
    num = 1;
  }
  else{
    num = num << 1;
  }
  delay(1000);  
}
