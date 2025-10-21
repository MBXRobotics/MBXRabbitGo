#include <MBXRabbitGo.h>

/*------------------------------------RGB Command ----------------------------------------------------

rgbSetbrightness(bright);
rgbSetColor(pinNum, color);
rgbSetMixColorRGB(pinNum, r, g, b);
rgbFillColor(color);
rgbFillRGB(r, g, b); 
showRainbow(wait);
theaterChaseRainbow(wait);
rgbClear();

--------------------------------------Pick Colors----------------------------------------------------------
 BLACK 
 WHITE 
 RED 
 GREEN 
 BLUE 
 YELLOW 
 MAGENTA 
 CYAN    
 ORANGE   
 LEMON 
 PINK 
 NAVY      
 DARKGREEN 
 DARKCYAN 
 MAROON 
 PURPLE 
 OLIVE 
 LIGHTGREY 
 DARKGREY 
*/


void setup() {
  MBX_ROBOTICS_SETUP();
  rgbSetbrightness(50);
}

void loop() {
  rgbSetColor(1, GREEN);
  delay(1000);
  rgbSetMixColorRGB(2, 255, 180, 0);
  delay(1000);
  rgbFillColor(BLUE);
  delay(1000);
  rgbFillRGB(192, 192, 192);
  delay(1000);
  showRainbow(20);
  delay(1000);
  theaterChaseRainbow(20);
  delay(1000);
}