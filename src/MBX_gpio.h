/*------------------------------------------GPIO MAPING AND FUNCTION-------------------------------------------*/
#include "pins_arduino.h"
#include "esp32-hal-adc.h"
#include <Arduino.h>

#ifndef GPIO_PIN_H
#define GPIO_PIN_H

#define A2D0 17
#define A2D1 19
#define A2D2 5
#define A2D3 14
#define A0 35
#define A1 36

static int currentPWMResolution = 8;
static int maxPWMValue = 255;
/*-------------------------------------------GPIO PIN MAPING ------------------------------------------------*/

int setPin(int pin) {
  switch (pin) {
    case 0: return A2D0;
    case 1: return A2D1;
    case 2: return A2D2;
    case 3: return A2D3;
    case 4: return A0;
    case 5: return A1;
    default: return -1;
  }
}

/*------------------------------------DIGITAL AND ANALOG FUNCTION-----------------------------------------------*/

int readAnalogIn(int pin) {
  int realPin = setPin(pin);
  if (realPin == -1) return -1;
  return analogRead(realPin);
}

bool digitalOutput(int pin, int state) {
  int realPin = setPin(pin);
  if (realPin == -1) return false;
  pinMode(realPin, OUTPUT);
  digitalWrite(realPin, state);
  return true;
}

int digitalInput(int pin) {
  int realPin = setPin(pin);
  if (realPin == -1) return -1;
  pinMode(realPin, INPUT);
  return digitalRead(realPin);
}

int digitalInputPullup(int pin) {
  int realPin = setPin(pin);
  if (realPin == -1) return -1;
  pinMode(realPin, INPUT_PULLUP);
  return digitalRead(realPin);
}


bool setPWMResolution(int bits) {
  if (bits < 1 || bits > 16) return false;  // ESP32 supports 1-16 bits
  currentPWMResolution = bits;
  maxPWMValue = (1 << bits) - 1;
  analogWriteResolution(bits, currentPWMResolution);
  return true;
}


bool writeAnalogOut(int pin, int value) {
  int realPin = setPin(pin);
  if (realPin == -1) return false;
  if (value < 0) value = 0;
  if (value > maxPWMValue) value = maxPWMValue;
  pinMode(realPin, OUTPUT);
  analogWrite(realPin, value);
  return true;
}

/*---------------------------------------------------END FUNCTION------------------------------------------------*/

#endif