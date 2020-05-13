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
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB = 0x20;
  // == *(unsigned char*)(0x25) = 0x20;
  delay(1000);
  PORTB = 0x00;
  // == *(unsigned char*)(0x25) = 0x00;
  delay(1000);
}
