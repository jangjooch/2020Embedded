int output = 3;
int duty = 0;

const byte interruptPin1 = 2;
volatile unsigned long pwm_value = 0;
volatile unsigned long timer = 0;

volatile unsigned long pwmValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(output, OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(interruptPin1), calcPWM1, CHANGE);
  analogWrite(output, 191);
}

unsigned long past = 0;

void loop() {
  // put your main code here, to run repeatedly:
  
  /*
  if(past == 0){
    past = millis();
  }
  else{
    if(millis() - past > 1000){      
      long motor = map( pwm_value,1000,2000,0,255);
      Serial.print(pwm_value);
      Serial.print("  ");
      Serial.println(motor);
      analogWrite(output, motor);
      past = 0;
    }
  }
  */
}


void calcPWM1(){
  if(digitalRead(interruptPin1) == HIGH){
    timer = micros();
  }
  else{
    if(timer != 0){     
      pwm_value = micros() - timer;
      if(pwm_value < 1100){
        pwm_value = 0;
      }
      else if(pwm_value > 1900){
        pwm_value = 1900;
      }
    }
  }
}
