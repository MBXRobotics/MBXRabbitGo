#include <MBXRabbitGo.h>  

void setup() {           
  MBXSetup();  // Initialize pins, PWM, drivers, sensors, etc.
}

void loop() {     
  waitForStart();  
  beep();
  forWard(50);  
  delay(2000);

  turnRight(50);  
  delay(2000);   

  backWard(50); 
  delay(2000);  

  turnLeft(50); 
  delay(2000);   

  motorStopAll();  
}
