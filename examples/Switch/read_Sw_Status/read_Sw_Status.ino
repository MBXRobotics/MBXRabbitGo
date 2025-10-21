#include <MBXRabbitGo.h>

void setup() {
  MBX_ROBOTICS_SETUP();
}

void loop() {
  Serial.print("SW = ");
  Serial.print(read_Sw_Status());
  Serial.println("");
  delay(100);
}