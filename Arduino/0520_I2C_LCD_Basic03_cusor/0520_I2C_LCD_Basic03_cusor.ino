#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// arduino ide 버전에따라 printBYTE 함수의 메커니즘을 바꾸기 위함
#if defined(ARDUINO) && ARDUINO >=100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

LiquidCrystal_I2C lcd(0x20, 16, 2);
// lcd 객체선언 및 주소 초기화

void setup() {
  // put your setup code here, to run once:
  lcd.init(); // lcd 사용 선언
  lcd.backlight(); // lcd 불켜기
  lcd.clear();
  lcd.print("HaHaHa");
  lcd.setCursor(0, 1); // col, row
  // 커서를 0렬 1행 으로 이동
  lcd.print("setCursor(0,1)");
}

int backLightState = LOW;
long previousMillis = 0;
long interval = 1000;

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval){
    previousMillis = currentMillis;
    if(backLightState == LOW)
      backLightState = HIGH;
    else
      backLightState = LOW;
    if(backLightState == HIGH)
      lcd.backlight();
    else
      lcd.noBacklight();
  }
}
