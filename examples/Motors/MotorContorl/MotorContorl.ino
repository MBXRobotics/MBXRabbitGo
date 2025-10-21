#include <MBXRabbitGo.h>

void setup() {
  MBX_ROBOTICS_SETUP();
}

void loop() {
  motor(1, 50);    //motor 1 forward
  motor(2, 50);    //motor 2 forward
  delay(2000);     //delay time 2 Second
  motor(1, -50);   //motor 1 backward
  motor(2, -50);   //motor 2 backward
  delay(2000);     //delay time 2 Second
  motorStopAll(1000,0);  // motorStopAll with delay 1 second and mode 0 //\\ NOTE: (if mode = 1 will continue if mode = 0 will stop immediately)
}