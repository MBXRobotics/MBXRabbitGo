// #ifndef SERVO_H
// #define SERVO_H

// #include <ESP32Servo.h>
// #define SVPin1 
// Servo serVo1;

// void servo(uint8_t pin, uint16_t angle) {
//   angle = constrain(angle, 0, 180);

//   switch (pin) {
//     case 1:
//       if (angle == -1) {
//         serVo1.detach();
//       } else {
//         if (!(serVo1.attached())) {
//           serVo1.attach(SVPin1);
//           delay(50); 
//         }
//         serVo1.write(angle);
//       }
//       break;
//     default:
//       break;
//   }
// }


// #endif 