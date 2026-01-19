#include <MBXRabbitGo.h>

void setup() {
  MBXSetup();
}

void loop() {
  motor(1, 50);    //motor 1 forward
  motor(2, 50);    //motor 2 forward
  delay(2000);     //delay time 2 Second
  motor(1, -50);   //motor 1 backward
  motor(2, -50);   //motor 2 backward
  delay(2000);     //delay time 2 Second
  motorStopAll();
}