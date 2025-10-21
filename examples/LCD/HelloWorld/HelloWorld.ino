#include <MBXRabbitGo.h>

/* 

oledClear();
display.fillScreen(Color);
display.setRotation(value);
display.setCursor(x, y);
display.setTextSize(value); 
display.setTextColor(Color1, Color2);
display.print(value);

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
  MBX_ROBOTICS_SETUP();
  oledClear();
}

void loop() {
  display.setTextSize(3);
  display.setCursor(15, 120);
  display.setTextColor(TFT_PURPLE);
  display.println(String("Hello World"));
}

