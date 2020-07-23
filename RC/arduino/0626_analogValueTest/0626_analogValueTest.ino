const byte interruptPin1 = 2;
const byte interruptPin2 = 3;

volatile unsigned long pwm_value[2] = {0,0};
volatile unsigned long timer[2] = {0,0};

void setup() {
  // put your setup code here, to run once:

  
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), calcPWM1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), calcPWM2, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  duartion();  
}

void calcPWM1(){
  if(digitalRead(interruptPin1) == HIGH){
    timer[0] = micros();
  }
  else{
    if(timer[0] != 0){
      pwm_value[0] = micros() - timer[0];
    }
  }
}

void calcPWM2(){
  if(digitalRead(interruptPin2) == HIGH){
    timer[1] = micros();
  }
  else{
    if(timer[1] != 0){
      pwm_value[1] = micros() - timer[1];
    }
  }
}

void duartion(){
  Serial.println(String(pwm_value[0]) + " " + String(pwm_value[1]));
}
