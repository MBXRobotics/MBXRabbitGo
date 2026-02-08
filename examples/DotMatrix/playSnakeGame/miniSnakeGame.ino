#include <MBXRabbitGo.h>

/*
=============> COMMAND <===============
dotClear();
dotShow();
dotSetBrightness(uint8_t level);
dotShowAt(uint8_t row, uint8_t col, bool on);
dotshow2Char(const char* txt);
dotshowScrollText(const char* txt, uint16_t speedMs = 80);
dotshowFirework(uint16_t speedMs = 60);
dotshowRainFall(uint16_t frames = 80, uint16_t speedMs = 60);
dotEvilEyes(); 
dotEyes(uint16_t frameDelayMs = 20);

  dotShowAt(0, 0, true);
  delay(1000);
  dotshowScrollText("hellow world");
  delay(1000);
  dotshowFirework();
  delay(1000);
  dotshowRainFall();
  delay(1000);
  dotEvilEyes();
  delay(1000);
  dotEyes();
  delay(1000);
*/

void setup() {
  MBXSetup();
  JoyController_Setup();
}

void loop() {
  JoyController();
  playminiSnakeGame();
}
