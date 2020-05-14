
int state = LOW;
int ledSelect = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(3, state);digitalWrite(4, state);digitalWrite(5, state);
  attachInterrupt(0, ledChange, RISING);
  // Interupt 0번을 사용할 것이다.
  // 이때 Interrupt0번은 digital 2번의 입력에 따라 작동된다.
  // 가운데 인자는 실행될 함수가 들어가면 된다.
  // Mode는 HIGH, LOW, RISING, FALLING, CHANGE가 있다.
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledSelect, state);
}

void ledChange(){
  ledSelect++;
  if(ledSelect > 5){
    ledSelect = 3;
  }
  state = !state;
}
