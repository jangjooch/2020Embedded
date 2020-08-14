
volatile unsigned long meauTimer[2] = {0, 0};
volatile unsigned long meauPwm[2] = {0, 0};
// 메뉴 입력
// 상|중|하  상|중|하
// 상 -> ARM // 상 하
// 하 -> Car // 상 하

volatile char mode = 0;
// 0 = ARM1
// 1 = ARM2
// 2 = CAR

volatile unsigned long timer[4] = {0, 0, 0, 0};
volatile unsigned long pwmValue[4] = {0, 0, 0, 0};
volatile long setAngel[4] = {90, 90, 90, 90};
volatile long motor = 0;
volatile char CW[4] = {0, 0, 0, 0};
volatile char Break[4] = {0, 0, 0, 0};

long mapping(long x,long in_min,long in_max, long out_min, long out_max);

void setup() {
  
  // Motor 제어 Duty Cycle 생성 16bit timer
  TCCR1A = 0xAA;
  // COM1A1 COM1A0 COM1B1 COM1B0 COM1C1 COM1C0 WGM11 WGM10
  // 1010 1010 -> ICR 만날시 Set
  // WGM11 WGM10 : 1 0 -> 14번모드 1 1 1 0 을 위함
  TCCR1B = 0x1A;
  // ICNC1 ICES1 - WGM13 WGM12 CS12 CS11 CS10
  // WGM13 WGM12 : 1 1 -> 14번모드 1 1 1 0 을 위함
  // CS12 CS11 CS10 : 분주율 8 -> 0 1 0 을 위함
  TCCR1C = 0x00;
  ICR1 = 40000;
  // TOP 설정
  // 분주 = 1/16 * 8 * 40000 = 20000nanoSec = 20ms
  // Duty Cycle 설정
  DDRB = 0xF0;
  // OCR1A, B, C PB5, 6, 7 출력
  
  TCCR3A = 0x82;
  TCCR3B = 0x1A;
  TCCR3C = 0x00;
  ICR3 = 40000;
  
  DDRE = 0x0F;
  // OC3A 출력  -> PE3
  // INT 4 입력 -> PE4
  DDRC = 0xF0;
  
  // pwm 입력측정을 위한 외부 Interrupt
  EICRA = 0x55;
  // ISC31 ISC30 ISC21 ISC20 | ISC11 ISC10 ISC01 ISC00
  // INT 3, 2, 1, 0
  // Change 설정 Change -> 0 1
  EIMSK = 0x0F;
  // INT 3, 2, 1, 0 Enable
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //OCR1A = mapping(setAngel[0] , 0, 180, 1000, 5000);
  //OCR1B = mapping(setAngel[1] , 0, 180, 1000, 5000);
  //OCR1C = mapping(setAngel[2] , 0, 180, 1000, 5000);
  //OCR3A = mapping(setAngle[3], 0, 180, 1000, 5000);
  
  
  Serial.print(pwmValue[0]);
  Serial.print(" ");
  Serial.print(pwmValue[1]);
  Serial.print(" ");
  Serial.print(pwmValue[2]);
  Serial.print(" ");
  Serial.println(pwmValue[3]);
  
  Serial.print(setAngel[0]);
  Serial.print(" ");
  Serial.print(setAngel[1]);
  Serial.print(" ");
  Serial.print(setAngel[2]);
  Serial.print(" ");
  Serial.println(setAngel[3]);
  
  delay(1000);
}

ISR(INT0_vect){
  INT_Method(0);
}
ISR(INT1_vect){
  INT_Method(1);
}
ISR(INT2_vect){
  INT_Method(2);
}
ISR(INT3_vect){
  INT_Method(3);
}

void INT_Method(int a){
  if( (PIND & (1 << a) ) ){
    timer[a] = micros();
  }
  else{
    PORTC = 0x00;
    if(timer[a] != 0){
      pwmValue[a] = micros() - timer[a];
      if(pwmValue[a] > 400000){
        
      }
      else{
        if(pwmValue[a] < 1250){
          setAngel[a]--;
        }
        else if(pwmValue[a] > 1750){
          setAngel[a]++;
        }
        if(setAngel[a] > 180){
          setAngel[a] = 180;
        }
        else if(setAngel[a] < 0){
          setAngel[a] = 0;
        }
      }
    }
  }
}
long mapping(long x,long in_min,long in_max, long out_min, long out_max)
{
  if(x > in_max){
    x = in_max;
  }
  else if(x < in_min){
    x = in_min;
  }
  long result = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return result;
}
