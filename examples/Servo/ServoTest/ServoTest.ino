#include <MBXRabbitGo.h>

void setup() {
  MBXSetup();
}

void loop() {

  servoWrite(1, 0);
  delay(1000);  // wait a second

  servoWrite(1, 50);
  delay(1000);  // wait a second

  servoWrite(1, 100);
  delay(1000);  // wait a second

  servoWrite(1, 180);
  delay(1000);  // wait a second
}
