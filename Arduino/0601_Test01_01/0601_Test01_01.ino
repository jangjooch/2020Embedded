#include <LiquidCrystal_I2C.h>

// 버튼 1
// 버튼 클릭하면 숫자 하나 증가
// 버튼 1초이상 누르고 있을 시 0.5초단위로 증가

// 버튼 2
// 0으로 리셋
#define UpPin 8
#define DownPin 12

LiquidCrystal_I2C lcd(0x20, 16, 2);
// char line01[17] = "0";
unsigned long num = 0;

int upButtonState;
int downButtonState;
int lastUpButton = LOW;
int lastDownButton = LOW;
unsigned long lastUpDebounceTime = 0;
unsigned long lastDownDebounceTime = 0;
unsigned long debounceDelay = 50;
unsigned long startUp = 0;
unsigned long conseUpStart = 0;
unsigned long conseUpEnd = 0;
int trigger = 0;
// 0 은 그냥
// 1은 1초이상 확인

void setup() {
  // put your setup code here, to run once:
  pinMode(UpPin, INPUT);
  pinMode(DownPin, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcdPrint();
}

void loop() {
  // put your main code here, to run repeatedly:
  int up = digitalRead(UpPin);
  int down = digitalRead(DownPin);
  
  if(up != lastUpButton){
    lastUpDebounceTime = millis();
  }
  if(up == HIGH){
    if(startUp == 0){
      startUp = millis();  
      Serial.println("Conse Start");
    }
  }
  else{
    startUp = 0;
    trigger = 0;
    conseUpStart = 0;
  }
  if(((startUp - millis()) > 1000) && (startUp != 0)){    
    if(conseUpStart == 0){
      trigger = 1;
      Serial.println("conseUpStart") ;
      conseUpStart = millis();
    }
  }
  else{
    
  }
  // 트리거가 0일때 작동하도록 한다.
  if (((millis() - lastUpDebounceTime) > debounceDelay)) {
    if(up != upButtonState){
      upButtonState = up;
      if(upButtonState == HIGH){
        Serial.println("num+");
        num++;
        //lcdPrint();
      }
    }
  }
  if(trigger == 1){
    if((conseUpStart - millis()) > 500){
      num++;
      Serial.println("num++");
      //lcdPrint();
    }
  }

  // ============================
  if(down != lastDownButton){
    lastDownDebounceTime = millis();
  }
  // Button Down
  // resolving deboucing problem by software
  if ((millis() - lastDownDebounceTime) > debounceDelay) {        
    if(down != downButtonState){
      downButtonState = down;
      if(downButtonState == HIGH){
        Serial.println("reset");
        num = 0;
      }
    }
  }
  lastUpButton = up;
  lastDownButton = down;
}

void lcdPrint(){
  Serial.println("lcd print");
  Serial.println(num);
  lcd.clear();
  //lcd.print("1111");
}
