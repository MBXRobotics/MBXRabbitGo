#include <MBXRabbitGo.h>

/* 

lcdClear();
lcd.fillScreen(Color);
lcd.setRotation(value);
lcd.setCursor(x, y);
lcd.setTextSize(value); 
lcd.setTextColor(Color1, Color2);
lcd.print(value);

/* --------------------------------- TFT Color -----------------------------------

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
  lcd.setTextSize(3);
  lcd.setCursor(15, 120);
  lcd.setTextColor(TFT_PURPLE);
  lcd.println(String("Hello World"));
}
