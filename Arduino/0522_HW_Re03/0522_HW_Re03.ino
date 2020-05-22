// LAST Version

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <EEPROM.h>
#include <TimerOne.h>
#include "pitches.h"
int melody01[] = {
NOTE_C5,NOTE_C5,NOTE_C5,NOTE_C5,NOTE_C5,
NOTE_E5,NOTE_G5,NOTE_G5,NOTE_E5,NOTE_C5,
NOTE_G5,NOTE_G5,NOTE_E5,NOTE_G5,NOTE_G5,NOTE_E5,
NOTE_C5,NOTE_C5,NOTE_C5,

NOTE_G5,NOTE_G5,NOTE_E5,NOTE_C5,
NOTE_G5,NOTE_G5,NOTE_G5,
NOTE_G5,NOTE_G5,NOTE_E5,NOTE_C5,
NOTE_G5,NOTE_G5,NOTE_G5,

NOTE_G5,NOTE_G5,NOTE_E5,NOTE_C5,
NOTE_G5,NOTE_G5,NOTE_G5,NOTE_A5,NOTE_G5,
NOTE_C6,NOTE_G5,NOTE_C6,NOTE_G5,
NOTE_E5,NOTE_D5,NOTE_C5
};
int noteDurations01[]={
4,8,8,4,4,
4,8,8,4,4,
8,8,4,8,8,4,
4,4,2,
4,4,4,4,
4,4,2,
4,4,4,4,
4,4,2,
4,4,4,4,
8,8,8,8,2,
4,4,4,4,
4,4,2
};

#if defined(ARDUINO) && ARDUINO >=100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

#define SetPin 2
#define UpPin 8
#define DownPin 12
#define BuzzerPin 6

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
Time AL;

int modeChanging = 0;
// 0 Beginning
// 1 TimeGet -> AL 
// 2 AL -> timeSelect 0~6 is done display current time
// 3 Timeshow -> music select

int timeClk = 0;
// timeShow clk

void setup() {
  // put your setup code here, to run once:
  
  EEPROM.get(address, timeGet); // Call time from EEPROM

  // AL reset
  AL.state = timeGet.state;
  AL.hour = timeGet.hour;
  AL.mini = timeGet.hour;
  AL.sec = timeGet.sec;
  AL.music = timeGet.music;
  // Digital pin 2 Button interrupt
  attachInterrupt(0, setInterrupt, CHANGE);

  // timeClk Timer interrupt
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(TimeShowCLK);
  
  
  // lcd second line set
  line02Set();
  
  pinMode(SetPin, INPUT); // set Button
  pinMode(UpPin, INPUT); // up Button
  pinMode(DownPin, INPUT); // DOWN Button
  pinMode(BuzzerPin, OUTPUT);
  
  Serial.begin(9600);
  
  lcd.init(); // lcd 사용 선언
  lcd.backlight(); // lcd 불켜기
  // printing lcd
  lcdPrint();  
}

int upButtonState;
int downButtonState;
int lastUpButton = LOW;
int lastDownButton = LOW;
unsigned long lastUpDebounceTime = 0;
unsigned long lastDownDebounceTime = 0;
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

int alarmTrigger = 0;
int noteIdx = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int up = digitalRead(UpPin);
  int down = digitalRead(DownPin);
  if(up != lastUpButton){
    lastUpDebounceTime = millis();
  }  
  if(down != lastDownButton){
    lastDownDebounceTime = millis();
  }
  if(modeChanging == 1){
    if(mode == 1){
      timeSelect = 0;
      // 다시 0으로 초기화
      line02Set();
      lcdPrint();
    }
    modeChanging = 0;
  }
  if(modeChanging == 2){
    mode = 3; // TimeShow 모드로 변경한다.
    modeChanging = 0;
  }
  if(modeChanging == 3){  
    modeChanging = 0;
    mode = 4;
  }
  if(mode == 0 || mode == 1){
    lcd.cursor();
    CursorMethod();
  }  
  else{
    lcd.noCursor();
    lcd.noBlink();
  }
  if((mode == 3) && (timeClk == 1)){
    //Serial.println("Time Show mode");
    timeClk = 0;
    timeFlow();    
    line02Set();
    lcdPrint();
    if(AlarmRing() == 2){
      alarmTrigger = 1;
    }
  }
  else if((mode == 4) && (timeClk == 1)){
    timeClk = 0;    
    //musicView();
    lcdPrint();
  }
  //int Durations = 1000/noteDurations01[noteIdx];
  //tone(BuzzerPin, melody01[noteIdx], Durations);
  if(alarmTrigger){
    if(timeGet.music == 0){
      Serial.println("melody01");
      digitalWrite(BuzzerPin, HIGH);
      int Durations = 1000/noteDurations01[noteIdx];
      //tone(BuzzerPin, melody01[noteIdx], Durations);
      Serial.println(melody01[noteIdx]);
      Serial.println(Durations);
      int pauseBetweenNotes = Durations *1.3 ;
      delay(pauseBetweenNotes);
      //noTone(BuzzerPin);
      noteIdx++;
      if(noteIdx >= sizeof(melody01)/sizeof(int)){
        alarmTrigger = 0;
      }
    }
    else{
      Serial.println("melody02");
      digitalWrite(BuzzerPin, HIGH);
    }
  }
  else{    
    //noTone(BuzzerPin);
    digitalWrite(BuzzerPin, LOW);
  }

  // Button Up
  // resolving deboucing problem by software
  if ((millis() - lastUpDebounceTime) > debounceDelay) {    
    if(up != upButtonState){
      upButtonState = up;
      if(upButtonState == HIGH){
        Serial.println("Up");
        if(mode==0 || mode == 1){
          TimeUp();
          line02Set();
          lcdPrint();
        }
        else if(mode == 4){
          timeGet.music = 0;
          line02Set();
          lcdPrint();
          EEPROM.put(0,timeGet);
          mode = 3;
        }
      }
    }    
  }
  // Button Down
  // resolving deboucing problem by software
  if ((millis() - lastDownDebounceTime) > debounceDelay) {        
    if(down != downButtonState){
      downButtonState = down;
      if(downButtonState == HIGH){
        Serial.println("Down");
        if(mode==0 || mode == 1){          
          TimeDown();
          line02Set();
          lcdPrint();
        }
        else if(mode == 4){
          timeGet.music = 1;
          line02Set();
          lcdPrint();
          EEPROM.put(0, timeGet);
          mode = 3;
        }
      }
    }
  } 
  lastUpButton = up;
  lastDownButton = down;
}

// setting cursor so when setting time the user can easily find where to change
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

// when setting Alarm and Current time this will make time increase
void TimeUp(){ 
  if(timeSelect == 0){
    if(mode == 0){
      timeGet.state++;  
    }
    else if(mode == 1){
      AL.state++;
    }
    if(timeGet.state >= 2){
      timeGet.state = 0;
    }
    if(AL.state >= 2){
      AL.state = 0;
    }
  }
  else if(timeSelect == 1){
    if(mode ==0){
      timeGet.hour = timeGet.hour + 10;  
    }
    else if(mode == 1){
      AL.hour = AL.hour + 10;  
    }    
    if(timeGet.hour > 12){
      timeGet.hour = timeGet.hour - 20;
    }
    if(AL.hour > 12){
      AL.hour = AL.hour - 20;
    }
  }
  else if(timeSelect == 2){
    if(mode == 0){
      timeGet.hour = timeGet.hour + 1;
    }
    else if(mode == 1){
      AL.hour = AL.hour + 1;
    }    
    if(timeGet.hour > 12){
      timeGet.hour = 1;
    }
    if(AL.hour > 12){
      AL.hour = 1;
    }
  }
  else if(timeSelect == 3){
    if(mode == 0){
      timeGet.mini = timeGet.mini + 10;
    }
    else if(mode == 1){
      AL.mini = AL.mini + 10;
    }    
    if(timeGet.mini >= 60){
      timeGet.mini = timeGet.mini - 60;
    }
    if(AL.mini >= 60){
      AL.mini = AL.mini - 60;
    }
  }
  else if(timeSelect == 4){
    if(mode == 0){
      timeGet.mini++;  
    }
    else if(mode == 1){
      AL.mini++;
    }
    if(timeGet.mini >= 60){
      timeGet.mini = timeGet.mini - 60; 
    }
    if(AL.mini >= 60){
      AL.mini = AL.mini - 60; 
    }
  }
  else if(timeSelect == 5){
    if(mode == 0){
      timeGet.sec = timeGet.sec + 10;
    }
    else if(mode == 1){
      AL.sec = AL.sec + 10;
    }
    if(timeGet.sec >= 60){
      timeGet.sec = timeGet.sec - 60;
    }
    if(AL.sec >= 60){
      AL.sec = AL.sec - 60;
    }
  }
  else if(timeSelect == 6){
    if(mode == 0){
      timeGet.sec++;
    }
    else if(mode == 1){
      AL.sec++;
    }    
    if(timeGet.sec >= 60){
      timeGet.sec = timeGet.sec - 60; 
    }
    if(AL.sec >= 60){
      AL.sec = AL.sec - 60; 
    }
  }
}
// when setting Alarm and Current time this will make time decrease
void TimeDown(){
  if(timeSelect == 0){
    if(mode == 0){
      timeGet.state--;  
    }
    else if(mode == 1){
      AL.state--;
    }
    if(timeGet.state < 0){
      timeGet.state = 1;
    } 
    if(AL.state < 0){
      AL.state = 1;
    }
  }
  else if(timeSelect == 1){
    if(mode == 0){
      timeGet.hour = timeGet.hour - 10;  
    }
    else if(mode == 1){
      AL.hour = AL.hour - 10;
    }
    if(timeGet.hour < 0){
      timeGet.hour = timeGet.hour + 20;
    }
    if(AL.hour < 0){
      AL.hour = AL.hour + 20;
    }
  }
  else if(timeSelect == 2){
    if(mode == 0){
      timeGet.hour = timeGet.hour - 1;  
    }
    else if(mode == 1){
      AL.hour = AL.hour - 1;
    }    
    if(timeGet.hour < 1){
      timeGet.hour = 12;
    }
    if(AL.hour < 1){
      AL.hour = 12;
    }
  }
  else if(timeSelect == 3){
    if(mode == 0){
      timeGet.mini = timeGet.mini - 10;  
    }
    else if(mode == 1){
      AL.mini = AL.mini - 10;
    }    
    if(timeGet.mini < 0){
      timeGet.mini = timeGet.mini + 60;
    }
    if(AL.mini < 0){
      AL.mini = AL.mini + 60;
    }
  }
  else if(timeSelect == 4){
    if(mode == 0){
      timeGet.mini--;
    }
    else if(mode == 1){
      AL.mini--;
    }    
    if(timeGet.mini < 0){
      timeGet.mini = 59; 
    }
    if(AL.mini < 0){
      AL.mini = 59; 
    }
  }
  else if(timeSelect == 5){
    if(mode == 0){
      timeGet.sec = timeGet.sec - 10;  
    }
    else if(mode == 1){
      AL.sec = AL.sec - 10;
    }    
    if(timeGet.sec < 0){
      timeGet.sec = timeGet.sec + 60;
    }
    if(AL.sec < 0){
      AL.sec = AL.sec + 60;
    }
  }
  else if(timeSelect == 6){
    if(mode == 0){
      timeGet.sec--;  
    }
    else if(mode == 1){
      AL.sec--;
    }    
    if(timeGet.sec < 0){
      timeGet.sec = 59; 
    }
    if(AL.sec < 0){
      AL.sec = 59; 
    }
  }
}

// this will set the char[] which will use for lcd second line
void line02Set(){
  line01[0] = '\0';
  char simpleMessage[] = "Simple Project";
  strcat(line01,simpleMessage);

  line02[0] = '\0';
  if(mode == 0 || mode == 3){
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
  else if(mode == 1){
    if(AL.state){
      strcat(line02, "PM ");
    }
    else{
      strcat(line02, "AM ");
    }  
    char numsGet[3];
    sprintf(numsGet,"%d:",AL.hour);
    if(AL.hour < 10){
      numsGet[1] = numsGet[0];
      numsGet[0] = '0';
      numsGet[2] = ':';
    }
    strcat(line02, numsGet);
    sprintf(numsGet,"%d:",AL.mini);
    if(AL.mini < 10){
      numsGet[1] = numsGet[0];
      numsGet[0] = '0';
      numsGet[2] = ':';
    }
    strcat(line02, numsGet);
  
    sprintf(numsGet,"%d",AL.sec);
    if(AL.sec < 10){
      numsGet[1] = numsGet[0];
      numsGet[0] = '0';
      numsGet[2] = ' ';
    }    
    strcat(line02, numsGet);
    numsGet[0] = ' ';
    numsGet[1] = 'A';
    numsGet[2] = 'L';
    strcat(line02, numsGet);
  }
  Serial.println(line02);  
}

void lcdPrint(){
  Serial.println("LCD Print");
  Serial.print("TCCR0B = ");
  Serial.println(TCCR0B);
  Serial.print("TCCR2B = ");
  Serial.println(TCCR0B);

  if(mode == 4){
    lcd.clear();
    lcd.print("Three  Bears");
    lcd.setCursor(0,1);
    lcd.print("Spring Water");
  }
  else{
    lcd.clear();
    lcd.print(line01);
    lcd.setCursor(0, 1); // 0렬 1행으로 이동
    lcd.print(line02);
    Serial.println(line02);
//    lcd.setCursor(0, 1);
//    lcd.print("1234567890123456");
  }  
}

// when the clock goes if the time mataches the alarm it will return 2
int AlarmRing(){
  if(timeGet.state == AL.state){
    if(timeGet.hour == AL.hour){
      if(timeGet.mini == AL.mini){
        if(timeGet.sec == AL.sec){
          Serial.println("AlarmRing 2");
          return 2;
        }
      }
    }
  }
  return 1;
}

// clk increase by CLK
void timeFlow(){  
  int hh = timeGet.hour;
  int mm = timeGet.mini;
  int ss = timeGet.sec;
  int pmam = timeGet.state;
  ss++;
  if(ss >= 60){
    ss = 0;
    mm++;
    if(mm >= 60){
      mm = 0;
      hh++;
      if(hh >= 13){
        hh = 0;
        if(pmam == 1){
          pmam = 0;
        }
        else{
          pmam = 1;
        }
      }
    }
  }
  timeGet.hour = hh;
  timeGet.mini = mm;
  timeGet.sec = ss;
  timeGet.state = pmam;
}

unsigned long startTime;
unsigned long endTime;

unsigned long firstTime = 0;
unsigned long secondTime = 0;
int doubleTap = 1000;
int doubleCount = 0;

// digital pin 2 Interrupt
// each mode act different process
void setInterrupt(){
  int state = digitalRead(SetPin);
  if(state){
    startTime = millis();
    // when activate falling
  }
  else{
    endTime = millis();    
    // activate raising
    unsigned long distance = endTime - startTime;
    // calculate tthan if it longger than 3sec
    // change the mode and lcd
    if(mode == 0 || mode == 1){
      if((distance > 300) && (mode == 0)){
        mode++;
        modeChanging = 1;
        EEPROM.put(0,timeGet);
        AL.state = timeGet.state;
        AL.hour = timeGet.hour;
        AL.mini = timeGet.mini;
        AL.sec = timeGet.sec;
        AL.music = timeGet.music;
      }
      else{
        timeSelect++;
        // if the alarm set is finished
        // it will show clock
        if(mode == 1){
          if(timeSelect >= 7){
            modeChanging = 2;
          }          
        }
        else if(timeSelect >= 7){
          timeSelect = 0;
        }
      }      
    }
    if(mode == 3){
      if(alarmTrigger){
        alarmTrigger = 0;
      }
      else{
        if(firstTime == 0){
          firstTime = millis();
          secondTime = millis();
        }
        else{
          firstTime = secondTime;
          secondTime = millis();
        }
      
        if(firstTime == secondTime){
          Serial.println("Start");
        }
        else{
          if((secondTime - firstTime) < doubleTap){
            Serial.println("doubleTap");
            //mode = 2;
            modeChanging = 3;
            Serial.println("modeChanging 3");
          }
        }
      }
    }
  }
}

// clk method
void TimeShowCLK(){
  if(timeClk){
    timeClk = 0;
  }
  else{
    timeClk = 1;
  }
}
