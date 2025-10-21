#include <MBXRabbitGo.h>

void setup() {
  MBX_ROBOTICS_SETUP();
}

void loop() {
  waitForStart();
  buzzer.beep();
}
