#include "esp32-hal-gpio.h"
#include "HardwareSerial.h"
#include "MBX_ultrasonic.h"
#include "MBX_dotmatrix.h"
#include "MBX_buzzer.h"
#include "MBX_motor.h"
#include "MBX_servo.h"
#include "MBX_oled.h"
#include "MBX_gpio.h"
#include "MBX_rgb.h"

MBXBuzzer buzzer;

void MBX_ROBOTICS_SETUP() {
  Serial.begin(115200);
  display.init(240, 240);
  display.setRotation(3);
  pinMode(SW, INPUT);
  ultrasonicSetup();
  motorSetup();
  oledClear();
}
