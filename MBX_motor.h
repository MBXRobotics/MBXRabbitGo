#ifndef MBX_MOTOR_H
#define MBX_MOTOR_H

#include <Arduino.h>

/*---------------------------DEFINE MOTOR PINS--------------------------------*/
#define PWMA 25
#define AIN1 17
#define AIN2 19

#define PWMB 26
#define BIN1 5
#define BIN2 14

#define STBY 13

/*----------------------------MOTOR CONFIGURATION-------------------------------------*/

static const int motorPWMResolution = 12;    //  12-bit: 0..4095
static const int maxMotorSpeed      = 4095;  //  12-bit max duty
static const int pwmFrequency       = 20000; // 20kHz (quiet)


static const int PWM_CH_A = 0;
static const int PWM_CH_B = 1;

static const int MIN_DUTY = 900;  
static const int DEADZONE = 5;   
struct MotorConfig {
  int pwmPin;
  int pwmChannel;
  int in1Pin;
  int in2Pin;
};

static MotorConfig motors[2] = {
  { PWMA, PWM_CH_A, AIN1, AIN2 },  // Motor A
  { PWMB, PWM_CH_B, BIN1, BIN2 }   // Motor B
};

/*----------------------------MOTOR SETUP-------------------------------------*/
static inline void motorSetup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);   

  // stop state
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);

  delay(50);
  ledcSetup(PWM_CH_A, pwmFrequency, motorPWMResolution);
  ledcSetup(PWM_CH_B, pwmFrequency, motorPWMResolution);

  ledcAttachPin(PWMA, PWM_CH_A);
  ledcAttachPin(PWMB, PWM_CH_B);

  ledcWrite(PWM_CH_A, 0);
  ledcWrite(PWM_CH_B, 0);

  delay(50);
}

/*----------------------------INTERNAL: SPEED -> DUTY--------------------------------*/
static inline int speedToDuty(int speedAbs0to100) {
  speedAbs0to100 = constrain(speedAbs0to100, 0, 100);
  if (speedAbs0to100 == 0) return 0;
  return map(speedAbs0to100, 1, 100, MIN_DUTY, maxMotorSpeed);
}

/*----------------------------CORE MOTOR CONTROL-------------------------------------*/
// speedM: -100..100
static inline void motor(int num, int speedM) {
  if (num < 1 || num > 2) {
    Serial.println("Error: Invalid motor number. Use 1 or 2.");
    return;
  }
  if (abs(speedM) < DEADZONE) speedM = 0;

  speedM = constrain(speedM, -100, 100);
  MotorConfig& cfg = motors[num - 1];

  int duty = speedToDuty(abs(speedM));

  if (speedM > 0) {
    digitalWrite(cfg.in1Pin, HIGH);
    digitalWrite(cfg.in2Pin, LOW);
    ledcWrite(cfg.pwmChannel, duty);

  } else if (speedM < 0) {
    digitalWrite(cfg.in1Pin, LOW);
    digitalWrite(cfg.in2Pin, HIGH);
    ledcWrite(cfg.pwmChannel, duty);

  } else {
    // coast stop
    digitalWrite(cfg.in1Pin, LOW);
    digitalWrite(cfg.in2Pin, LOW);
    ledcWrite(cfg.pwmChannel, 0);
  }
}
/*---------------------------- MOTOR MOVEMENTS-------------------------------------*/
static inline void forWard(int speedM) {
  speedM = constrain(speedM, 0, 100);
  motor(1, speedM);
  motor(2, speedM);
}
static inline void backWard(int speedM) {
  speedM = constrain(speedM, 0, 100);
  motor(1, -speedM);
  motor(2, -speedM);
}
static inline void turnLeft(int speedM) {
  speedM = constrain(speedM, 0, 100);
  motor(1, 0);
  motor(2, speedM);
}
static inline void turnRight(int speedM) {
  speedM = constrain(speedM, 0, 100);
  motor(1, speedM);
  motor(2, 0);
}
static inline void spinLeft(int speedM) {
  speedM = constrain(speedM, 0, 100);
  if (speedM < 35) speedM = 35;  
  motor(1, -speedM);
  motor(2,  speedM);
}
static inline void spinRight(int speedM) {
  speedM = constrain(speedM, 0, 100);
  if (speedM < 35) speedM = 35;  
  motor(1,  speedM);
  motor(2, -speedM);
}
static inline void motorStopAll(){
  ledcWrite(PWM_CH_A, 0);
  ledcWrite(PWM_CH_B, 0);

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(STBY, HIGH);
}

#endif 
