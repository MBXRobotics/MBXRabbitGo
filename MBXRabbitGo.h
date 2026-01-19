// Copyright & inspiration by: EasyKidsRobotics

#include "esp32-hal-gpio.h"
#include "HardwareSerial.h"
#include "MBX_ultrasonic.h"
#include "MBX_dotmatrix.h"
#include "MBX_GamePad.h"
#include "MBX_buzzer.h"
#include "MBX_motor.h"
#include "MBX_servo.h"
#include "MBX_lcd.h"
#include "MBX_gpio.h"
#include "MBX_rgb.h"

void MBXSetup() {
  Serial.begin(115200);
  lcd.init(240, 240);
  lcd.setRotation(3);
  rgbSetbrightness(20);
  rgbFillColor(BLACK);
  pinMode(SW, INPUT);
  ultrasonicSetup();
  motorSetup();
  lcdClear();
}
