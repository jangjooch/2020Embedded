
char num;
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
  if(num & 0x80){
    // int 형을 사용했을 때와 달리 ==이 아닌
    // & AND 마스크를 통해 가져와야 한다.
    // 아스키 값이 0x7F 까지만 존재하기 때문에
    // 이미 0x80을 넘어버린 시점에서 비교가 불가능 하기에
    // 마스크를 사용하여 강제로 가져오도록 해야한다.
    state = 1;    
  }
  else if(num & 0x01){
    state = 0;
  }
  if(state){
    num = num >> 1;
  }
  else{
    num = num << 1;
  }
  
  PORTD = ~num;
  //Serial.println();
  delay(1000);  
}
