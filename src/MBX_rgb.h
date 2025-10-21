
#ifndef MBX_RGB_H
#define MBX_RGB_H

#include <Adafruit_NeoPixel.h>

#define RGB_PIN_FRONT 17
#define RGB_FRONT_COUT 14
/*---------------------------------------DEFINE COLOR------------------------------------------*/

#define BLACK 0x000000   /*   0,   0,   0 */
#define WHITE 0xFFFFFF   /* 255, 255, 255 */
#define RED 0xff0000     /* 255,   0,   0 */
#define GREEN 0x00ff00   /*   0, 255,   0 */
#define BLUE 0x0000ff    /*   0,   0, 255 */
#define YELLOW 0xffff00  /* 255, 255,   0 */
#define MAGENTA 0xFF00FF /* 255,   0, 255 */
#define CYAN 0x00ffff    /*   0, 255, 255 */
#define ORANGE 0xffa500  /* 255, 180,   0 */
#define LEMON 0x6dcd0a   /* 109, 255,   10 */
#define PINK 0xffc0cb
#define NAVY 0x000080      /*   0,   0, 128 */
#define DARKGREEN 0x006400 /*   0, 128,   0 */
#define DARKCYAN 0x008b8b  /*   0, 128, 128 */
#define MAROON 0xb03060    /* 128,   0,   0 */
#define PURPLE 0xa020f0    /* 128,   0, 128 */
#define OLIVE 0x808000     /* 128, 128,   0 */
#define LIGHTGREY 0xd3d3d3 /* 192, 192, 192 */
#define DARKGREY 0xa9a9a9  /* 128, 128, 128 */

Adafruit_NeoPixel rgb(RGB_FRONT_COUT, RGB_PIN_FRONT, NEO_GRB + NEO_KHZ800);

/*---------------------------------RGB Function----------------------------------------------------*/
void rgbSetbrightness(int bright) {
  rgb.setBrightness(bright);
}

void rgbSetColor(int pinNum, uint32_t color) {
  rgb.setPixelColor(pinNum, color);
  rgb.show();
}

void rgbSetMixColorRGB(int pinNum, int r, int g, int b) {
  rgb.setPixelColor(pinNum, rgb.Color(r, g, b));
}

void rgbFillColor(uint32_t color) {
  for (int i = 0; i < RGB_FRONT_COUT; i++) {
    rgb.setPixelColor(i, color);
  }
  rgb.show();
}

void rgbFillRGB(int r, int g, int b) {
  for (int i = 0; i < RGB_FRONT_COUT; i++) {
    rgb.setPixelColor(i, rgb.Color(r, g, b));
  }
  rgb.show();
}

void showRainbow(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    rgb.rainbow(firstPixelHue);
    rgb.show();
    delay(wait);
  }
}

void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;           // First pixel starts at red (hue 0)
  for (int a = 0; a < 30; a++) {   // Repeat 30 times...
    for (int b = 0; b < 3; b++) {  //  'b' counts from 0 to 2...
      rgb.clear();                 //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for (int c = b; c < rgb.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int hue = firstPixelHue + c * 65536L / rgb.numPixels();
        uint32_t color = rgb.gamma32(rgb.ColorHSV(hue));  // hue -> RGB
        rgb.setPixelColor(c, color);                      // Set pixel 'c' to value 'color'
      }
      rgb.show();                   // Update strip with new contents
      delay(wait);                  // Pause for a moment
      firstPixelHue += 65536 / 90;  // One cycle of color wheel over 90 frames
    }
  }
}

void rgbClear() {
  rgb.clear();
  rgb.show();
}

#endif

