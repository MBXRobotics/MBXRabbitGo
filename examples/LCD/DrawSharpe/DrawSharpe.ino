#include <MBXRabbitGo.h>

/*
lcd.drawLine(x1, y1, x2, y2, color);
lcd.drawFastHLine(x, y, w, color)
lcd.drawFastVLine(x, y, h, color)
lcd.drawRect(x, y, w, h, color);
lcd.fillRect(x, y, w, h, color);
lcd.drawRoundRect(x, y, w, h, radius, color);
lcd.fillRoundRect(x, y, w, h, radius, color);
lcd.drawCircle(x, y, radius, color);
lcd.fillCircle(x, y, radius, color);
lcd.drawTriangle(x1, y1, x2, y2, x3, y3, color);

----------------------------------------- TFT Color -------------------------------------------------------
TFT_BLACK 
TFT_NAVY 
TFT_DARKGREEN 
TFT_DARKCYAN 
TFT_MAROON 
TFT_PURPLE 
TFT_OLIVE 
TFT_LIGHTGREY 
TFT_DARKGREY 
TFT_BLUE 
TFT_GREEN 
TFT_CYAN 
TFT_RED 
TFT_MAGENTA 
TFT_YELLOW
TFT_WHITE 
TFT_ORANGE 
TFT_GREENYELLOW 
TFT_PINK 
*/

void setup() {
 MBXSetup();
 lcdClear();
}

void loop() {
  lcd.fillScreen(BLACK);
  lcd.drawLine(10, 10, 50, 10, TFT_BLUE);
  lcd.drawFastHLine(10, 30, 50, TFT_MAROON);
  lcd.drawFastVLine(80, 10, 50, TFT_GREEN);
  lcd.drawRect(10, 60, 30, 30, TFT_WHITE);
  lcd.fillRect(10, 100, 30, 30, TFT_PINK);
  lcd.drawRoundRect(120, 10, 30, 30, 4, TFT_GREEN);
  lcd.fillRoundRect(120, 50, 30, 30, 4, TFT_YELLOW);
  lcd.drawCircle(200, 30, 20, TFT_RED);
  lcd.fillCircle(200, 90, 20, TFT_MAGENTA);
  lcd.drawTriangle(10, 235, 50, 235, 30, 195, TFT_OLIVE);
  lcd.fillTriangle(70, 235, 110, 235, 90, 195, TFT_PURPLE);
  delay(2000);
}












