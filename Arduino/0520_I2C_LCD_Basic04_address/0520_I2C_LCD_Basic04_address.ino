#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// arduino ide 버전에따라 printBYTE 함수의 메커니즘을 바꾸기 위함
#if defined(ARDUINO) && ARDUINO >=100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

LiquidCrystal_I2C lcd(0x21, 16, 2);
// device address. 기본적으로 0x20이였지만
// 점퍼 A0를 해제함으로서 device address가 변경되어 0x21이 된다.

void setup() {
  // put your setup code here, to run once:
  lcd.init(); // lcd 사용 선언
  lcd.backlight(); // lcd 불켜기
  lcd.clear();
  lcd.print("HaHa");
  lcd.setCursor(0, 1);
  lcd.print("setCursor(0,1)");
}

int backLightState = LOW;
long previousMillis = 0;
long interval = 1000;

void loop() {
}
