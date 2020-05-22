#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <TimerOne.h>
#include <EEPROM.h>


#if defined(ARDUINO) && ARDUINO >=100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

#define SetPin 2
#define UpPin 10
#define DownPin 12

LiquidCrystal_I2C lcd(0x20, 16, 2);

char line01[17] = "Simple Project";
char line02[17];

int address = 0;

int mode = 0;
// 0 TimeSet mode
// 1 AL mode
// 2 Music mode
// 3 TimeShow mode

int timeSelect = 0;
// 0  AM/PM
// 1  10 hour
// 2  1  hour
// 3  10 mini
// 4  1  mini
// 5  10 sec
// 6  1  sec

struct Time{
  int state;
  int hour;
  int mini;
  int sec;
  int music;
};

Time timeGet;

void setup() {
  // put your setup code here, to run once:
  
  EEPROM.get(address, timeGet); // EEPROM에서 시간 불러와 적용
  
  
  // Set버튼 누르는 것에 대한 interrupt
  attachInterrupt(0, setInterrupt, CHANGE);
  //Timer1.initialize(1000000);
  //Timer1.attachInterrupt(LcdBlink);

  
  // 불러온 것들을 line02에 적용
  line02Set();
  
  pinMode(SetPin, INPUT); // set Button
  pinMode(UpPin, INPUT); // up Button
  pinMode(DownPin, INPUT); // DOWN Button
  
  Serial.begin(9600);
  
  lcd.init(); // lcd 사용 선언
  lcd.backlight(); // lcd 불켜기
  // timeGet인자들을 활용해 lcd 출력
  lcdPrint();  
}

int upButtonState;
int downButtonState;
int lastUpbutton = LOW;
int lastDownbutton = LOW;
unsigned long lastUpDebounceTime = 0;
unsigned long lastDownDebounceTime = 0;
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


void loop() {
  // put your main code here, to run repeatedly:
  int up = digitalRead(UpPin);
  int down = digitalRead(DownPin);
  
  if(mode == 0){
    lcd.cursor();
    CursorMethod();
    if(up){
      TimeUp();
      line02Set();
      lcdPrint();
    }
    if(down){
      
    }
  }
}

void CursorMethod(){  
  if(timeSelect == 0){    
    lcd.setCursor(1,1);
  }
  else if(timeSelect == 1){
    lcd.setCursor(3,1);
  }
  else if(timeSelect == 2){
    lcd.setCursor(4,1);
  }
  else if(timeSelect == 3){
    lcd.setCursor(6,1);
  }
  else if(timeSelect == 4){
    lcd.setCursor(7,1);
  }
  else if(timeSelect == 5){
    lcd.setCursor(9,1);
  }
  else if(timeSelect == 6){
    lcd.setCursor(10,1);
  }
}

void TimeUp(){
  if(timeSelect == 0){    
    timeGet.state++;
    if(timeGet.state >= 2){
      timeGet.state = 0;
    }    
  }
  else if(timeSelect == 1){
    timeGet.hour = timeGet.hour + 10;
    if(timeGet.hour > 12){
      timeGet.hour = timeGet.hour - 20;
    }
  }
  else if(timeSelect == 2){
    timeGet.hour = timeGet.hour + 1;
    if(timeGet.hour > 12){
      timeGet.hour = 1;
    }
  }
  else if(timeSelect == 3){
    timeGet.mini = timeGet.mini + 10;
    if(timeGet.mini >= 60){
      timeGet.mini = timeGet.mini - 60;
    }
  }
  else if(timeSelect == 4){
    timeGet.mini++;
    if(timeGet.mini >= 60){
      timeGet.mini = timeGet.mini - 60; 
    }
  }
  else if(timeSelect == 5){
    timeGet.sec = timeGet.sec + 10;
    if(timeGet.sec >= 60){
      timeGet.sec = timeGet.sec - 60;
    }
  }
  else if(timeSelect == 6){
    timeGet.sec++;
    if(timeGet.sec >= 60){
      timeGet.sec = timeGet.sec - 60; 
    }
  }
}

void line02Set(){
  line02[0] = '\0';
  if(timeGet.state){
    strcat(line02, "PM ");
  }
  else{
    strcat(line02, "AM ");
  }  
  char numsGet[3];
  sprintf(numsGet,"%d:",timeGet.hour);
  if(timeGet.hour < 10){
    numsGet[1] = numsGet[0];
    numsGet[0] = '0';
    numsGet[2] = ':';
  }
  strcat(line02, numsGet);
  
  sprintf(numsGet,"%d:",timeGet.mini);
  if(timeGet.mini < 10){
    numsGet[1] = numsGet[0];
    numsGet[0] = '0';
    numsGet[2] = ':';
  }
  strcat(line02, numsGet);
  
  sprintf(numsGet,"%d",timeGet.sec);
  if(timeGet.sec < 10){
    numsGet[1] = numsGet[0];
    numsGet[0] = '0';
    numsGet[2] = ' ';
  }
  strcat(line02, numsGet);  
}

void lcdPrint(){
  lcd.clear();
  lcd.print(line01);
  lcd.setCursor(0, 1); // 0렬 1행으로 이동
  lcd.print(line02);
}

unsigned long startTime;
unsigned long endTime;

unsigned long firstTime = 0;
int doubleTap = 1000;
int doubleCount = 0;

void setInterrupt(){
  int state = digitalRead(SetPin);
  if(state){
    startTime = millis();
    // 처음 눌렀을 때 기록
  }
  else{
    endTime = millis();    
    // 마지막 때었을 때 기록
    unsigned long distance = endTime - startTime;
    // 눌렀다가 때었을때의 차이를 계산
    if(mode == 0){
      if(distance > 3000){
        mode++;
      }
      else{
        timeSelect++;
        if(timeSelect >= 7){
          timeSelect = 0;
        }
      }
    }
    else if(mode == 1){
      
    }
  }
}

int backLightState = HIGH;

void LcdBlink(){
  // Interrupt으로 안되는 건가
  // 아니면 함수로 전달되는 거여서 안되는 건가
  // 그건 모르겠다
  // interrupt 내부에서 LCD에 접근하면 충돌이 일어난다고 하더라
  // https://forum.arduino.cc/index.php?topic=140588.0
  // https://forum.arduino.cc/index.php?topic=121006.0
  
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
