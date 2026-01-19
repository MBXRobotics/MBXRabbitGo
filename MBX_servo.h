#ifndef MBX_SERVO_H
#define MBX_SERVO_H

#include <Arduino.h>
#include <ESP32Servo.h>
#define SERVO1_PIN 27
#define SERVO_MIN_US 500
#define SERVO_MAX_US 2500

Servo SV1;
bool servo1Attached = false;
void servoWrite(uint8_t S_pin, int angle) {
  if (S_pin != 1) return;
  if (angle == -1) {
    if (SV1.attached()) SV1.detach();
    servo1Attached = false;
    return;
  }
  angle = constrain(angle, 0, 180);
  if (!servo1Attached) {
    ESP32PWM::allocateTimer(2);
    SV1.setPeriodHertz(50);
    SV1.attach(SERVO1_PIN, SERVO_MIN_US, SERVO_MAX_US);
    servo1Attached = true;
  }
  SV1.write(angle);
}

#endif
