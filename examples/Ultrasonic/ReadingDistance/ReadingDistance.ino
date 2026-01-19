#include <MBXRabbitGo.h>

// Example of reading distance 

void setup() {
  MBXSetup();
}

void loop() {
  Serial.println(getDistance());
  delay(50);
}

