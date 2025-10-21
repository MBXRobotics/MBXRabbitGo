#include <MBXRabbitGo.h>

// Example of reading distance 

void setup() {
  MBX_ROBOTICS_SETUP();
}

void loop() {
  Serial.println(getDistance());
  delay(50);
}

