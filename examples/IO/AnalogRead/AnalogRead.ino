#include <MBXRabbitGo.h>

void setup() {
  MBXSetup();
}

void loop() {
  Serial.println(analog(A1));
  delay(20);
}