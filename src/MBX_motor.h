#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include <ESP32Servo.h>

/*---------------------------DEFINE MOTOR PINS--------------------------------*/
#define PWMA 25
#define AIN1 33
#define AIN2 27
#define PWMB 26
#define BIN1 12
#define BIN2 13

/*----------------------------MOTOR CONFIGURATION-------------------------------------*/
static const int motorPWMResolution = 8;  // Try 8-bit first (0-255)
static const int maxMotorSpeed = 255;     // 8-bit max
static const int pwmFrequency = 1000;     // Lower frequency (1 kHz)

struct MotorConfig {
  int pwmPin;
  int in1Pin;
  int in2Pin;
};

MotorConfig motors[2] = {
  { PWMA, AIN1, AIN2 },  // Motor A
  { PWMB, BIN1, BIN2 }   // Motor B
};

/*----------------------------MOTOR SETUP-------------------------------------*/
void motorSetup() {
  Serial.println("\n=== Motor Setup Starting ===");

  // Configure direction control pins as outputs FIRST
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  // Set all to LOW initially
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);

  delay(100);

  // Configure PWM channels for both motors
  // Serial.println("Configuring PWM for Motor A (Pin 25)...");
  if (ledcAttach(PWMA, pwmFrequency, motorPWMResolution)) {
    // Serial.println("✓ Motor A PWM attached successfully");
  } else {
    // Serial.println("✗ Motor A PWM attach FAILED!");
  }

  // Serial.println("Configuring PWM for Motor B (Pin 26)...");
  if (ledcAttach(PWMB, pwmFrequency, motorPWMResolution)) {
    // Serial.println("✓ Motor B PWM attached successfully");
  } else {
    // Serial.println("✗ Motor B PWM attach FAILED!");
  }

  delay(100);
}

/*----------------------------CORE MOTOR CONTROL-------------------------------------*/
void motor(int num, int speedM) {
  if (num < 1 || num > 2) {
    Serial.println("Error: Invalid motor number. Use 1 or 2.");
    return;
  }

  speedM = constrain(speedM, -100, 100);

  int motorIndex = num - 1;
  MotorConfig& motorCfg = motors[motorIndex];

  if (speedM > 0) {
    // Forward direction
    int mappedSpeed = map(speedM, 0, 100, 0, maxMotorSpeed);
    digitalWrite(motorCfg.in1Pin, HIGH);
    digitalWrite(motorCfg.in2Pin, LOW);
    ledcWrite(motorCfg.pwmPin, mappedSpeed);

  } else if (speedM < 0) {
    // Reverse direction
    int mappedSpeed = map(-speedM, 0, 100, 0, maxMotorSpeed);
    digitalWrite(motorCfg.in1Pin, LOW);
    digitalWrite(motorCfg.in2Pin, HIGH);
    ledcWrite(motorCfg.pwmPin, mappedSpeed);

  } else {
    // Stop (coast mode for better control)
    digitalWrite(motorCfg.in1Pin, LOW);
    digitalWrite(motorCfg.in2Pin, LOW);
    ledcWrite(motorCfg.pwmPin, 0);
  }
}

/*---------------------------- MOTOR MOVEMENTS-------------------------------------*/
void forWard(int speedM) {
  speedM = constrain(speedM, 0, 100);
  motor(1, speedM);
  motor(2, speedM);
}

void backWard(int speedM) {
  speedM = constrain(speedM, 0, 100);
  motor(1, -speedM);
  motor(2, -speedM);
}

void turnLeft(int speedM) {
  speedM = constrain(speedM, 0, 100);
  motor(1, 0);
  motor(2, speedM);
}

void turnRight(int speedM) {
  speedM = constrain(speedM, 0, 100);
  motor(1, speedM);
  motor(2, 0);
}

void spinLeft(int speedM) {
  speedM = constrain(speedM, 0, 100);
  motor(1, -speedM);
  motor(2, speedM);
}

void spinRight(int speedM) {
  speedM = constrain(speedM, 0, 100);
  motor(1, speedM);
  motor(2, -speedM);
}

void motorStopAll(uint32_t wait_ms = 0, uint8_t mode = 0) {
  ledcWrite(PWMA, 0);
  ledcWrite(PWMB, 0);
  if (mode == 0) {
    // soft brake
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);

#ifdef STBY
    pinMode(STBY, OUTPUT);
    digitalWrite(STBY, LOW);
#endif

    if (wait_ms) delay(wait_ms);
    while (true) {
      delay(1000);
    }
  } else if (mode == 1) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, HIGH);
    if (wait_ms) delay(wait_ms);
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    if (wait_ms) delay(wait_ms);
  }
}

#endif