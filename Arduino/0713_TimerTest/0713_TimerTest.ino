unsigned long doorStart = 0;
unsigned char doorState = 0;

unsigned long buzzerStart = 0;
unsigned char buzzerState = 0;

unsigned long past = 0;
unsigned long idx = 0;

void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  TCCR3A = 0x82;
  // COMA1 COMA0 : 1 0 -> ICR1을 만나면 Clear
  // WGM11 WGM10 : 1 0 -> 14번모드 1 1 1 0 을 위함
  TCCR3B = 0x1A;
  // WGM13 WGM12 : 1 1 -> 14번모드 1 1 1 0 을 위함
  // CS12 CS11 CS10 : 분주율 8 -> 0 1 0 을 위함
  TCCR3C = 0x00;
  // PWM모드에서는 출력할 것이 없다.
  ICR3 = 40000;
  OCR3A = 2000;
  // TOP 설정
  // 분주 = 1/16 * 8 * 40000 = 20000nanoSec = 20ms
  // Duty Cycle 설정
  DDRE |= 0x08;
  // OCR3A
  
  DDRC = 0xF0;
  // Buzzer
  PORTC = 0x00;

  DDRD = 0xF0;

  // Button Int0
  EICRA = 0b00001010;
  EIMSK = 0x03;
  PORTD = 0x03;
  
  TCCR2 = 0x05;
  TCNT2 = 0;
  TIMSK = 0x40;
  
  SREG |= 0x80;
}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER2_OVF_vect){
  idx++;
  
  Serial.print("tip");
  Serial.print(idx);
  Serial.print("  ");
  Serial.println(doorStart);
  PORTC = 0xF0;
  
  if(doorState){
    if( (idx - doorStart) > 500){
      doorStart = 0;
      doorState = 0;
      idx = 0;
      OCR3A = 1000;
    }
  }
}


ISR(INT0_vect){
  Door_Open();
}


void Door_Open(){
  doorStart = idx;
  OCR3A = 5000;
  doorState = 1;
}

void BuzzerActivate(int a){
  buzzerStart = millis();
  buzzerState = a;
  PORTC |= 0x80;
}
