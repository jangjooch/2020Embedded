#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(12, INPUT);
  lcd.init();
  //lcd.backlight();
  lcd.clear();  
}

unsigned long startUp = 0;
unsigned long startDown = 0;
int trigger = 0;
unsigned long conseStart = 0;
int num = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int up = digitalRead(8);
  int down = digitalRead(12);
  if(up){
    if(startUp == 0){
      startUp = millis();
    }
  }
  else{
    if(startUp != 0){
      unsigned long res = startUp - millis();            
      // 딸깍
      if( res > 50){
        num++;
        Serial.println(num);
      }
      startUp = 0;
    }
  }
  
  if((startUp != 0)){
    if((millis() - startUp) > 1000){
      trigger = 1;  
    }    
  }
  else{
    trigger = 0;
  }
  
  if(trigger){
    if(conseStart == 0){
      conseStart = millis();
    }
    else if((millis() - conseStart) > 500){
      conseStart = 0;
      num++;
      Serial.println(num);
    }
  }
  if(down){
    num = 0;
  }
}
