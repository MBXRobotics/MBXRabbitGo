#include <MBXRabbitGo.h>

void setup() {
  MBXSetup();
  lcd.fillScreen(BLACK);
}

void loop() {
  // http://www.rinkydinkelectronics.com/t_imageconverter565.php
  lcd.drawRGBBitmap(0, 0, MBXLOGO, 240, 240);
  delay(1000);
}
