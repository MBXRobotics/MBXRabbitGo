//inspiration by: EasyKidsRobotics  

/*------------------------------------------GPIO MAPING AND FUNCTION-------------------------------------------*/
#include "pins_arduino.h"
#include "esp32-hal-adc.h"
#include <Arduino.h>

#ifndef GPIO_PIN_H
#define GPIO_PIN_H

#define A0 12
#define A1 33
#define A2 39
#define A4 36

#define D0 12
#define D1 33
/*---------------------------------------------------Function Analog------------------------------------------------*/

int analog(int pin) {
  if (pin == 0) pin = A0;
  else if (pin == 1) pin = A1;
  else if (pin == 2) pin = A2;
  else if (pin == 3) pin = A4;
  return analogRead(pin);
}
/*---------------------------------------------------Function DigitalOut------------------------------------------------*/

void digitalOpen(int pin, int state) {
  if (pin == 0) pin = D0;
  else if (pin == 1) pin = D1;
  pinMode(pin, OUTPUT);
  digitalWrite(pin, state);
}
/*---------------------------------------------------Function DigitalIn------------------------------------------------*/

int digitalIn(int pin) {
  if (pin == 0) pin = A0;
  else if (pin == 1) pin = A1;
  else if (pin == 2) pin = A2;
  else if (pin == 3) pin = A4;
  pinMode(pin, INPUT);
  return digitalRead(pin);
}
/*---------------------------------------------------Function DigitalIn_Pullup------------------------------------------------*/

int digitalIn_Pullup(int pin) {
  if (pin == 0) pin = A0;
  else if (pin == 1) pin = A1;
  else if (pin == 2) pin = A2;
  else if (pin == 3) pin = A4;
  pinMode(pin, INPUT_PULLUP);
  return digitalRead(pin);
}

/*---------------------------------------------------END FUNCTION------------------------------------------------*/
#endif
