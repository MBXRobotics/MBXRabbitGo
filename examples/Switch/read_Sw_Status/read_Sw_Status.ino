#include <MBXRabbitGo.h>

void setup() {
 MBXSetup();
}

void loop() {
  Serial.print("SW = ");
  Serial.print(read_Sw_Status());
  Serial.println("");
  delay(100);
}