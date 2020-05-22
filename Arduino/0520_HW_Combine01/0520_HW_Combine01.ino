#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <TimerOne.h>

#if defined(ARDUINO) && ARDUINO >=100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

LiquidCrystal_I2C lcd(0x20, 16, 2);

char line01[17] = "Simple Project";
char line02[17];

int address = 0;
unsigned long startTime;
unsigned long endTime;

int mode = 0;
// 0 TimeSet mode
// 1 AL mode
// 2 Music mode
// 3 TimeShow mode

int timeSelect = 0;
// 0  AM/PM
// 1  hour
// 2  mini
// 3  sec

struct Time{
  int state;
  int hour;
  int mini;
  int sec;
  int music;
};

void setup() {
  // put your setup code here, to run once:
  Time timeGet;
  EEPROM.get(address, timeGet); // EEPROM에서 시간 불러와 적용
  // 불러온 것들을 line02에 적용
  if(timeGet.state){
    strcat(line02, "PM ");
  }
  else{
    strcat(line02, "AM ");
  }
  // Set버튼 누르는 것에 대한 interrupt
  //attachInterrupt(0, setInterrupt, CHANGE);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(LcdBlink);
  // timeGet인자들을 활용해 lcd 출력
  char numsGet[3];
  sprintf(numsGet,"%d:",timeGet.hour);
  strcat(line02, numsGet);
  sprintf(numsGet,"%d:",timeGet.mini);
  strcat(line02, numsGet);
  sprintf(numsGet,"%d",timeGet.sec);
  strcat(line02, numsGet);  
  
  pinMode(13, INPUT); // set Button
  pinMode(12, INPUT); // up Button
  pinMode(11, INPUT); // DOWN Button
  
  Serial.begin(9600);
  
  lcd.init(); // lcd 사용 선언
  lcd.backlight(); // lcd 불켜기
  lcdPrint();  
}

void loop() {
  // put your main code here, to run repeatedly:

}
void lcdPrint(){
  lcd.clear();
  lcd.print(line01);
  lcd.setCursor(0, 1); // 0렬 1행으로 이동
  lcd.print(line02);
}

void setInterrupt(){
  int state = digitalRead(2);
  if(state){
    startTime = millis();
    // 처음 눌렀을 때 기록
  }
  else{
    endTime = millis();
    // 마지막 때었을 때 기록
    if((endTime - startTime) >= 3000){
      if(mode){
        mode = 0;        
      }
      else{
        mode = 1;
      }
    }
    else{
      
    }
  }
}

int backLightState = HIGH;

void LcdBlink(){
  Serial.println(" LcdBlink");
  if(mode == 0){
    if(backLightState){
      //lcd.backlight();
      Serial.println("ON");
    }
    else{
      //lcd.noBacklight();
      Serial.println("OFF");
    }
    backLightState = !backLightState;
  }
}
