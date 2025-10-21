/*------------------------------------------Start-------------------------------------------*/

#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H
#include <Arduino.h>

#define  TRIG_PIN  32
#define  ECHO_PIN  34
#define SW 0
/*------------------------------------------Switch function-------------------------------------------*/

void waitForStart() {
  while (digitalRead(0) == 1) { delay(500); }
}

int read_Sw_Status() {
  return digitalRead(0);
}

/*------------------------------------------End Switch function-------------------------------------------*/
/*------------------------------------------Sonar function-------------------------------------------*/

#define MAX_DISTANCE_CM 400
#define TIMEOUT_US 23000
#define TRIGGER_PULSE_US 10

void ultrasonicSetup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);
}

float microsecondsToCentimeters(long microseconds) {
  return microseconds / 29.1 / 2.0;
}

float getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);


  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(TRIGGER_PULSE_US);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, TIMEOUT_US);


  if (duration == 0) {
    return 0;
  }

  float distanceCm = microsecondsToCentimeters(duration);

  if (distanceCm > MAX_DISTANCE_CM || distanceCm < 2.0) {
    return -1.0;
  }

  return distanceCm;
}
#endif
/*------------------------------------------end sonar function-------------------------------------------*/
