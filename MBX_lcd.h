//inspiration by: EasyKidsRobotics

/*--------------------------------------------------------------DEFINE------------------------------------------------------------------*/
#ifndef OLED_H
#define OLED_H
#include "MBX_logo.h"
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include "TFT_eSPI.h"
#define TFT_CS 15
#define TFT_DC 2
#define TFT_RST 4
#define TFT_SCLK 18
#define TFT_MOSI 23

Adafruit_ST7789 lcd(TFT_CS, TFT_DC, TFT_RST);

/*---------------------------------------------------WELLCOME TO MBX ROBOTICS------------------------------------------------------------------*/
void lcdShowMBXLogo() {
  lcd.drawRGBBitmap(0, 0, MBXLOGO, 240, 240);
}


void wellcomeToMBX() {
  lcd.fillScreen(TFT_BLACK);
  const char* lines[] = { "Wellcome", "To", "MBX", "Robotics" };
  uint16_t colors[] = { TFT_RED, TFT_GREEN, TFT_WHITE, TFT_BLUE };
  int numLines = 4;
  int y = 20;
  for (int i = 0; i < numLines; i++) {
    int textSize = 4;
    if (strcmp(lines[i], "MBX") == 0) {
      textSize = 6;
    }
    lcd.setTextSize(textSize);
    int16_t x1, y1;
    uint16_t w, h;
    lcd.getTextBounds(lines[i], 0, y, &x1, &y1, &w, &h);
    int16_t centerX = (lcd.width() - w) / 2;
    for (int x = -w; x <= centerX; x += 6) {
      lcd.fillRect(0, y1, lcd.width(), h, TFT_BLACK);
      lcd.setCursor(x, y);
      lcd.setTextColor(colors[i]);
      lcd.print(lines[i]);
      delay(15);
    }
    y += h + 10;
  }
}


void lcdClear() {
  lcd.fillScreen(TFT_BLACK);
}

/*---------------------------------------------------VR------------------------------------------------------------------*/

#define VR 35
int showVr;

int vr(int setValue) {
  int valueVr = analogRead(VR);
  int mapValue = map(valueVr, 0, 4095, setValue, 0);
  return mapValue;
}

void servoTest(int pin) {
  lcd.setTextSize(4);
  lcd.setCursor(65, 50);
  lcd.setTextColor(TFT_BLUE);
  lcd.println("Servo");
  lcd.setTextColor(TFT_GREEN);
  lcd.setCursor(75, 100);
  lcd.println("Test");
  // lcd.setTextFont(GLCD);
  lcd.setTextSize(4);
  lcd.setCursor(88, 150);
  lcd.setTextColor(0x0);
  lcd.println(showVr);
  showVr = vr(180);
  lcd.setTextSize(4);
  lcd.setCursor(88, 150);
  lcd.setTextColor(TFT_WHITE);
  lcd.println(showVr);
  servoWrite(pin, showVr);
  delay(50);

  // lcd.setTextSize(4);
  // lcd.setCursor(56, 50);
  // lcd.setTextColor(TFT_MAGENTA);
  // lcd.println("Servo:");
  // lcd.setTextColor(TFT_GREEN);
  // lcd.setCursor(75, 100);
  // lcd.println("Test:");
}


//  Example 1: show RGB
// example 2: show hello world in center
// example 3: Change rotation:
// example 3: Different text sizes:
// example 4: Change text colors:
// 6. Draw lines
// 7. Rectangle frame
// 8. Filled rectangle
// 9. Draw circle
#endif
/*-----------------------------------------------------------------------END------------------------------------------------------------------*/

/*---------------------------------------EXAMPLE OF USAGE THE TFT lcd------------------------------------------------------------------*/

// http://www.rinkydinkelectronics.com/t_imageconverter565.php
//lcd.begin(w,h);
//lcd.setRotation(value); // 0-3
//lcd.setTextSize(value);
//lcd.fillScreen(TFT_Color);
//lcd.setTextColor(TFT_Color, TFT_Color);
//lcd.setFreeFont(myfont)
//lcd.drawString("TEXT", x, y);
//lcd.print(value);
//lcd.pushImage(0,0,240,240,EasyKidsLogo);
//lcd.setCursor(x, y);
//lcd.drawLine(x0, y0, x1, y1, TFT_Color);
//lcd.drawRect(x, y, w, h, TFT_Color);
//lcd.fillRect(x, y, w, h, TFT_Color);
//lcd.drawRoundRect(x, y, w, h, r, TFT_Color);
//lcd.fillRoundRect(x, y, w, h, r, TFT_Color);
//lcd.drawCircle(x, y, r, TFT_Color);
//lcd.fillCircle(x, y, r, TFT_Color);
//lcd.drawEllipse(x, y, rx, ry,TFT_Color);
//lcd.fillEllipse(x, y, rx, ry,TFT_Color);
//lcd.drawTriangle(x1, y1, x2, y2, ,x3, y3, TFT_Color);
//lcd.fillTriangle(x1, y1, x2, y2, ,x3, y3, TFT_Color);


// // New color definitions use for all my libraries
// #define TFT_BLACK 0x0000       /*   0,   0,   0 */
// #define TFT_NAVY 0x000F        /*   0,   0, 128 */
// #define TFT_DARKGREEN 0x03E0   /*   0, 128,   0 */
// #define TFT_DARKCYAN 0x03EF    /*   0, 128, 128 */
// #define TFT_MAROON 0x7800      /* 128,   0,   0 */
// #define TFT_PURPLE 0x780F      /* 128,   0, 128 */
// #define TFT_OLIVE 0x7BE0       /* 128, 128,   0 */
// #define TFT_LIGHTGREY 0xC618   /* 192, 192, 192 */
// #define TFT_DARKGREY 0x7BEF    /* 128, 128, 128 */
// #define TFT_BLUE 0x001F        /*   0,   0, 255 */
// #define TFT_GREEN 0x07E0       /*   0, 255,   0 */
// #define TFT_CYAN 0x07FF        /*   0, 255, 255 */
// #define TFT_RED 0xF800         /* 255,   0,   0 */
// #define TFT_MAGENTA 0xF81F     /* 255,   0, 255 */
// #define TFT_YELLOW 0xFFE0      /* 255, 255,   0 */
// #define TFT_WHITE 0xFFFF       /* 255, 255, 255 */
// #define TFT_ORANGE 0xFDA0      /* 255, 180,   0 */
// #define TFT_GREENYELLOW 0xB7E0 /* 180, 255,   0 */
// #define TFT_PINK 0xFC9F

/* 

// =========================
//   TASK FUNCTIONS
// =========================

// 1. Clear screen in different colors
void task1_colors() {
  lcd.fillScreen(TFT_RED);   delay(1000);
  lcd.fillScreen(TFT_GREEN); delay(1000);
  lcd.fillScreen(TFT_BLUE);  delay(1000);
  lcd.fillScreen(TFT_BLACK); delay(1000);
}

// 2. Show text in the center
void task2_centerText() {
  lcd.fillScreen(TFT_BLACK);
  lcd.setTextSize(3);
  lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  lcd.setCursor(60, 100);
  lcd.println("Hello TFT");
  delay(2000);
}

// 3. Change rotation
void task3_rotation() {
  for (int r = 0; r < 4; r++) {
    lcd.setRotation(r);
    lcd.fillScreen(TFT_BLACK);
    lcd.setTextSize(2);
    lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
    lcd.setCursor(20, 100);
    lcd.printf("Rotation %d", r);
    delay(2000);
  }
  lcd.setRotation(3); // back to default
}

// 4. Different text sizes
void task4_sizes() {
  lcd.fillScreen(TFT_BLACK);
  for (int s = 1; s <= 6; s++) {
    lcd.setTextSize(s);
    lcd.setCursor(10, 30 * s);
    lcd.setTextColor(TFT_GREEN, TFT_BLACK);
    lcd.printf("Size %d", s);
  }
  delay(3000);
}

// 5. Change text colors
void task5_colors() {
  uint16_t colors[] = {TFT_RED, TFT_GREEN, TFT_YELLOW, TFT_CYAN, TFT_WHITE, TFT_MAGENTA};
  const char* names[] = {"RED","GREEN","YELLOW","CYAN","WHITE","MAGENTA"};
  lcd.fillScreen(TFT_BLACK);
  lcd.setTextSize(2);
  for (int i = 0; i < 6; i++) {
    lcd.setTextColor(colors[i], TFT_BLACK);
    lcd.setCursor(40, i * 30);
    lcd.println(names[i]);
  }
  delay(3000);
}

// 6. Draw lines
void task6_lines() {
  lcd.fillScreen(TFT_BLACK);
  lcd.drawLine(0, 0, 240, 240, TFT_RED);
  lcd.drawLine(240, 0, 0, 240, TFT_GREEN);
  lcd.drawLine(0, 120, 240, 120, TFT_BLUE);
  lcd.drawLine(120, 0, 120, 240, TFT_YELLOW);
  delay(3000);
}

// 7. Rectangle frame
void task7_rectFrame() {
  lcd.fillScreen(TFT_BLACK);
  lcd.drawRect(10, 10, 220, 220, TFT_RED);
  delay(3000);
}

// 8. Filled rectangle
void task8_fillRect() {
  lcd.fillScreen(TFT_BLACK);
  lcd.fillRect(60, 60, 120, 120, TFT_YELLOW);
  delay(3000);
}

// 9. Draw circle
void task9_circle() {
  lcd.fillScreen(TFT_BLACK);
  lcd.drawCircle(120, 120, 50, TFT_CYAN);
  delay(3000);
}

// 10. Crosshair
void task10_crosshair() {
  lcd.fillScreen(TFT_BLACK);
  lcd.drawLine(0, 120, 240, 120, TFT_WHITE);
  lcd.drawLine(120, 0, 120, 240, TFT_WHITE);
  delay(3000);
}

// 11. Moving text
void task11_movingText() {
  for (int x = 0; x < 200; x += 10) {
    lcd.fillScreen(TFT_BLACK);
    lcd.setTextSize(3);
    lcd.setTextColor(TFT_GREEN, TFT_BLACK);
    lcd.setCursor(x, 100);
    lcd.println("LCD");
    delay(100);
  }
}

// 12. Loading bar
void task12_loadingBar() {
  lcd.fillScreen(TFT_BLACK);
  lcd.drawRect(20, 120, 200, 20, TFT_WHITE);
  for (int i = 0; i <= 200; i++) {
    lcd.fillRect(20, 120, i, 20, TFT_BLUE);
    delay(20);
  }
  delay(1000);
}

// 13. Blinking text
void task13_blinkText() {
  for (int i = 0; i < 6; i++) {
    lcd.fillScreen(TFT_BLACK);
    if (i % 2 == 0) {
      lcd.setTextSize(4);
      lcd.setTextColor(TFT_RED, TFT_BLACK);
      lcd.setCursor(80, 100);
      lcd.println("HELLO");
    }
    delay(500);
  }
}

// 14. Rainbow screen
void task14_rainbow() {
  for (int y = 0; y < 240; y++) {
    uint16_t color = lcd.color565(y, 255 - y, y / 2);
    lcd.drawFastHLine(0, y, 240, color);
  }
  delay(3000);
}

// 15. Bouncing ball
void task15_bounceBall() {
  int x = 50, y = 50, dx = 3, dy = 2;
  for (int i = 0; i < 200; i++) {
    lcd.fillScreen(TFT_BLACK);
    lcd.fillCircle(x, y, 20, TFT_YELLOW);
    x += dx; y += dy;
    if (x < 20 || x > 220) dx = -dx;
    if (y < 20 || y > 220) dy = -dy;
    delay(50);
  }
}

// 16. Digital clock (fake time)
void task16_clock() {
  for (int s = 0; s < 10; s++) {
    lcd.fillScreen(TFT_BLACK);
    lcd.setTextSize(3);
    lcd.setTextColor(TFT_GREEN, TFT_BLACK);
    lcd.setCursor(50, 100);
    lcd.printf("12:34:%02d", s);
NEW SKETCH

    delay(1000);
  }
}

// 17. Temperature demo
void task17_temp() {
  for (int i = 0; i < 10; i++) {
    int temp = random(20, 40);
    lcd.fillScreen(TFT_BLACK);
    lcd.setTextSize(3);
    lcd.setTextColor(TFT_RED, TFT_BLACK);
    lcd.setCursor(40, 100);
    lcd.printf("Temp: %d C", temp);
    delay(1000);
  }
}

// 18. Graph plot
void task18_graph() {
  lcd.fillScreen(TFT_BLACK);
  int x = 0, y = 120;
  for (int i = 0; i < 200; i++) {
    int newY = random(80, 160);
    lcd.drawLine(x, y, x + 1, newY, TFT_GREEN);
    x++; y = newY;
    delay(30);
  }
  delay(1000);
}

// 19. Four corners
void task19_corners() {
  lcd.fillScreen(TFT_BLUE);
  lcd.setTextSize(3);
  lcd.setTextColor(TFT_RED, TFT_BLUE);
  lcd.setCursor(0, 0); lcd.println("LCD");
  lcd.setCursor(180, 0); lcd.println("LCD");
  lcd.setCursor(0, 210); lcd.println("LCD");
  lcd.setCursor(180, 210); lcd.println("LCD");
  delay(2000);
}

// 20. Menu system
void task20_menu() {
  const char* menu[3] = {"Start", "Settings", "Exit"};
  for (int sel = 0; sel < 3; sel++) {
    lcd.fillScreen(TFT_BLACK);
    for (int i = 0; i < 3; i++) {
      if (i == sel) {
        lcd.setTextColor(TFT_BLACK, TFT_YELLOW);
      } else {
        lcd.setTextColor(TFT_WHITE, TFT_BLACK);
      }
      lcd.setTextSize(3);
      lcd.setCursor(60, 60 + i * 40);
      lcd.println(menu[i]);
    }
    delay(1500);
  }
}

*/
