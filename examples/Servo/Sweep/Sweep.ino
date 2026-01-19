
#include <MBXRabbitGo.h>

// --------------EXAMPLE OF HOW TO USE SWEEP-------------------
//  void servoWrite(uint8_t S_pin, int angle).
int i;

void setup() {
MBXSetup();
}

void loop() {

for(i = 20; i < 130; i+=2){
  servoWrite(1,i);
  delay(20);
}

for(i = 130; i > 20; i-=2){
  servoWrite(1,i);
  delay(20);
}

}
