#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x20, 16, 2);
// 0x20 은 주소
// 16은 length
// 2는 line

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Hello, world!");
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    delay(100);
    lcd.clear();
    while(Serial.available()>0){
      lcd.write(Serial.read());
    }
  }
}
