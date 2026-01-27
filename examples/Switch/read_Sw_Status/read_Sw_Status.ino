#include <MBXRabbitGo.h>

void setup() {
 MBXSetup();
}

void loop() {
  Serial.print("SW = ");
  Serial.print(sw_Start());
  Serial.println("");
  delay(100);
}
