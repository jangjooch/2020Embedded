void setup() {
  // put your setup code here, to run once:
  mypinMode(2,INPUT);
  mypinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mydigitalRead(2)){
    mydigitalWrite(13,HIGH);
  }
  else{
    mydigitalWrite(13,LOW);
  }
}

void mypinMode(int pin, int mode){  
  if(mode == OUTPUT){
    if(pin <=7){
      DDRD |= (1<<pin);
      // PORTD의 어떠한 곳을 1로 변환하여 OUTPUT으로 변환할 것인지 정한다.
    }
    else{
      DDRB |= (1<<(pin-8));
      // PORTB의 어떠한 곳을 1로 변환하여 OUTPUT으로 변환할 것인지 정한다.
      // pin-8을 하는 이유는 PORTB는 8번부터 받기 때문이다.
    }
  }
  else if(mode == INPUT){
    if(pin <=7){
      DDRD &= ~(1 << pin);
      // PORTD의 어떠한 곳을 0로 변환하여 INPUT으로 변환할 것인지 정한다.
    }
    else{
      DDRB &= ~(1<<(pin-8));
      // PORTB의 어떠한 곳을 0로 변환하여 INPUT으로 변환할 것인지 정한다.
      // pin-8을 하는 이유는 PORTB는 8번부터 받기 때문이다.
    }
  }
}

void mydigitalWrite(int pin, int value){
  if(pin<=7){
    if(value == HIGH){
      PORTD |= (1<<pin);
      // 내가 원하는 핀에 따라 해당하는 PORTD의 bit에 HIGH입력을 주기 위함이다.
    }
    else{
      PORTD &= ~(1<<pin);
      // 내가 원하는 핀에 따라 해당하는 PORTD의 bit에 LOW입력을 주기 위함이다.
    }
  }
  else{
    if(value == HIGH){
      PORTB |= (1<<(pin-8));
      // 내가 원하는 핀에 따라 해당하는 PORTB의 bit에 HIGH입력을 주기 위함이다.
    }
    else{
      PORTB &= ~(1<<(pin-8));
      // 내가 원하는 핀에 따라 해당하는 PORTB의 bit에 LOW입력을 주기 위함이다.
    }
  }
}

int mydigitalRead(int pin){
  if(pin<=7){
    return (PIND & (1<<pin));
    // 내가 원하는 핀의 값을 저장하고 있는 PIND의 값을 읽어내기 위해
    // 1과의 AND연산을 통하여 return 하여 해당 비트의 값을 반환한다.
  }
  else{
    return (PINB & (1<<(pin-8)));
    // 내가 원하는 핀의 값을 저장하고 있는 PINB의 값을 읽어내기 위해
    // 1과의 AND연산을 통하여 return 하여 해당 비트의 값을 반환한다.
  }
}
