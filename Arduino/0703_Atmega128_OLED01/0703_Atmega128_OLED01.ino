#include <U8g2lib.h>
#include <U8x8lib.h>

U8X8_SSD1306_64X32_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup() {
  // put your setup code here, to run once:
  DDRA = 0x01;
  DDRD = 0x03;
  PORTD = 0x00;

  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.refreshDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(0,0,"Hello World!");
  u8x8.drawString(0,20,"00a00");
  PORTA = 0x01;
  delay(1000);
  PORTA = 0x00;
  delay(1000);
}
