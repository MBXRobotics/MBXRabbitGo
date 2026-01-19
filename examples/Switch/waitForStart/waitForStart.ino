#include <MBXRabbitGo.h>

void setup() {
  MBXSetup();
}

void loop() {
  waitForStart();
  buzzer.beep();
}
