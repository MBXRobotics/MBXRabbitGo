#include <MBXRabbitGo.h>

void setup() {
  MBX_ROBOTICS_SETUP();
   display.fillScreen(BLACK);
}

void loop() {
  // http://www.rinkydinkelectronics.com/t_imageconverter565.php
  display.drawRGBBitmap(0, 0, MBXLOGO, 240, 240);
  delay(1000);
}
