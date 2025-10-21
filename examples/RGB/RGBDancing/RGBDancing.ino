#include <MBXRabbitGo.h>

/*

------------------------------------RGB Command ----------------------------------------------------

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
  rgbSetbrightness(80);
}

void loop() {
  theaterChaseRainbow(20);
}