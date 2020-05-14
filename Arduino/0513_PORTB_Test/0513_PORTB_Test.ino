/*
UNO 회로설계도와 Atmega328의 회로도를 확인한다.
GPIO의 PWM의 13번핀은 PB5 이다.
즉 13번핀을 출력으로 설정하고 싶다면 
PB5을 1로 설정하여 츨력이 가능하도록 하면 된다.
즉 DDRB를 0x20을 통해 PB5를 활성화 시킨것이라 생각하면 된다.
각 명령어 밑에 주석처리가 되어있는 것은 실제로 작동되는 것이다.
주석처리가 되지 않은것은 이미 설정으로 선언되어 있는 것이다

 */

void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;
  // == *(unsigned char*)(0x24) = 0x20;
  // 이것은 DDRB는 PortB Data Direction Register를 의미하는데
  // 해당 0x20은 0010 0000 이기에 이는 DataSheet를 보면 알 수 있듯이
  // DDB5에 HIGH를 할당한다는 것을 의미한다.
  // 즉 setup 단계에서 PORTB5에 해당하는 Register를 사용하겠다고
  // 설정하는 것이다.
  // 그리고 PORTB5는 13번핀과 연결되어 있다.
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB = 0x20;
  // == *(unsigned char*)(0x25) = 0x20;
  // PORTB의 주솟값이 0x25이다.
  // 해당 주소값의 값을 0x20로 초기화하는 것이다
  // 0x20은 8진수이지만 2진수로 바꾸어보면
  // 0010 0000 이다. 이는 PORTB에서 PORTB5 부분에 해당하는
  // 곳에 HIGH라는 입력을 준것과 같다.
  delay(1000);
  PORTB = 0x00;
  // == *(unsigned char*)(0x25) = 0x00;
  delay(1000);
}
