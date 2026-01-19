#include <MBXRabbitGo.h>

void setup() {
  MBXSetup();
}

void loop() {
  digitalOpen(1, HIGH);
  delay(100);
  digitalOutOpen(1, LOW);
  delay(100);
}