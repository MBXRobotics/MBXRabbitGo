#include <MBXRabbitGo.h>  // Include MBX RabbitGo framework header

void setup() {           // Arduino setup function (runs once at boot)
  MBX_ROBOTICS_SETUP();  // Initialize pins, PWM, drivers, sensors, etc.
}

void loop() {      // Main loop (runs repeatedly)
  waitForStart();  // Block here until the start condition (e.g., button press)
  buzzer.beep();
  forWard(50);  // Drive forward at ~50% speed
  delay(2000);  // Keep moving forward for 2 seconds

  turnRight(50);  // Turn/pivot right at ~50% speed
  delay(2000);    // Hold the right turn for 2 seconds

  backWard(50);  // Drive backward at ~50% speed
  delay(2000);   // Keep reversing for 2 seconds

  turnLeft(50);  // Turn/pivot left at ~50% speed
  delay(2000);   // Hold the left turn for 2 seconds

  motorStopAll(100, 0);  // Stop motors: wait 100 ms, mode 0 = hard-stop and BLOCK forever
}  // (program will not continue past this line when mode == 0)
