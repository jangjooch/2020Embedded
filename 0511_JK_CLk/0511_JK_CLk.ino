
int clkstate = 0;
int aold = 0; int asending = 0;
int bold = 0; int bsending = 0;
int cold = 0; int csending = 0;
int dold = 0; int dsending = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); // CLK
  
  pinMode(3, OUTPUT); // a
  pinMode(4, OUTPUT); // b
  pinMode(5, OUTPUT); // c
  pinMode(6, OUTPUT); // d
}

void loop() {
  // put your main code here, to run repeatedly:

  JK7476(clk(), &aold, &asending, 3);
  JK7476(asending, &bold, &bsending, 4);
  JK7476(bsending, &cold, &csending, 5);
  JK7476(csending, &dold, &dsending, 6);
  delay(1000);
  asending = 0;
  bsending = 0;
  csending = 0;
  dsending = 0;
}

int clk(){ // 0과 1을 반복해서 반환
  if(clkstate){
    clkstate = 0;
    digitalWrite(2,HIGH);
    return 1;
  }  
  else{
    clkstate = 1;
    digitalWrite(2,LOW);
    return 0;
  }
}

void JK7476(int clk, int *old, int *sending, int pin){
  // clk는  전 단계로 부터 sending을 받음
  // old는 해당 핀의 전 상태
  // sending은 다음 단계로 보내는 출력

  if(clk){
    // 전 단계에서 sending 을 받으면
    if(*old){
      // 만약 이전 내용이 1 이라면      
      digitalWrite(pin,  LOW);
      *sending = 1;
      // 다음단계를 위한 출력에 1을 주고
      *old = 0;
      // 현재 low임으로 0을 준다
    }
    else{
      // 만약 이전 내용이 0 이라면
      digitalWrite(pin,  HIGH);      
      *old = 1;
      // 현재 low임으로 0을 준다
    }
    
  }
  else{
    
  }  
}
