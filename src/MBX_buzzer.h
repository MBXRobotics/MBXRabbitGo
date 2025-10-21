#ifndef MBX_MELODY_H
#define MBX_MELODY_H

#include <Arduino.h>
#include "pitchesX.h"

#define BUZZER_PIN 16
#define LED_PIN 2 


// Baby Shark melody
const int babyShark_melody[] = {
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4,
  0,
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4,
  0,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, 
};

const int babyShark_durations[] = {
  2, 2, 4, 4, 4, 8, 4, 8, 4,
  4, 4, 4, 4, 4, 8, 4, 8, 4,
  4, 4, 4, 4, 4, 8, 4, 8, 4, 4, 4, 2,
  2, 
  2, 2, 4, 4, 4, 8, 4, 8, 4,
  4, 4, 4, 4, 4, 8, 4, 8, 4,
  4, 4, 4, 4, 4, 8, 4, 8, 4, 4, 4, 2, 
  2, 
  2, 2, 4, 4, 4, 8, 4, 8, 4,
  4, 4, 4, 4, 4, 8, 4, 8, 4,
  4, 4, 4, 4, 4, 8, 4, 8, 4, 4, 4, 2, 
};

// Happy birthday melody
const int ifYoureHappy_melody[] = {
  NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_F4,
  NOTE_E4, NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_C4, NOTE_C4,
  NOTE_C5, NOTE_A4, NOTE_F4, 
  NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4,
  NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_F4
};

const int ifYoureHappy_durations[] = {
  4, 8, 
  4, 4, 4,
  2, 4, 8, 
  4, 4, 4,
  2, 4, 8,
  4, 4, 4, 
  4, 4, 4, 8,
  4, 4, 4,
  2
};

class MBXBuzzer {
private:
  uint8_t buzzerPin;
  
public:
  MBXBuzzer(uint8_t buzzer = BUZZER_PIN) {
    buzzerPin = buzzer;
   
  }
  
  
void playTone(int frequency, int duration) {
    if (frequency == 0 || frequency == REST) {
      noTone(buzzerPin);
      delay(duration);
    } else {
      tone(buzzerPin, frequency);
      delay(duration);
      noTone(buzzerPin);
    }
  }
  
  void stopTone() {
    noTone(buzzerPin);
  }

  void playUploadSuccessFull() {
    playTone(NOTE_C4, 150);
    playTone(NOTE_G3, 150);
    playTone(NOTE_G3, 150);
    playTone(NOTE_C4, 150);
    playTone(NOTE_G4, 150);
    playTone(NOTE_C5, 300);
  }
  
  void playPartty() {
    for (int freq = 2000; freq > 200; freq -= 50) {
      playTone(freq, 10);
    }
  }

  void playSpaceshipSound() {
    for (int i = 0; i < 3; i++) {
      glide(100, 1000, 200);
      glide(1000, 100, 200);
    }
  }
  
  // Glide effect
  void glide(int startFreq, int endFreq, int duration) {
    int steps = 50;
    int stepDelay = duration / steps;
    int freqStep = (endFreq - startFreq) / steps;
    
    for (int i = 0; i <= steps; i++) {
      int currentFreq = startFreq + (freqStep * i);
      tone(buzzerPin, currentFreq);
      delay(stepDelay);
    }
    
    noTone(buzzerPin);
  }
  
  // Play kids songs
  void playBabyShark() {
    playSong(babyShark_melody, babyShark_durations, 
             sizeof(babyShark_melody)/sizeof(int), 200);
  }

  void playHappyBirthday() {
    playSong(ifYoureHappy_melody, ifYoureHappy_durations, 
             sizeof(ifYoureHappy_melody)/sizeof(int), 180);
  }

  void playPoliceSiren() {
    for (int cycle = 0; cycle < 4; cycle++) {
      for (int freq = 600; freq <= 1200; freq += 15) {
        tone(buzzerPin, freq);
        delay(4);
      }
      delay(50);
      for (int freq = 1200; freq >= 600; freq -= 15) {
        tone(buzzerPin, freq);
        delay(4);
      }
      delay(50);
    }
    
    noTone(buzzerPin);
  }

  void beep() {
    tone(buzzerPin, 500, 100);
    delay(100);
    delay(200);
  }

private:
  void playSong(const int* melody, const int* durations, int length, int tempo) {
    for (int i = 0; i < length; i++) {
      int noteDuration = (60000 / tempo) * (4.0 / durations[i]);
      playTone(melody[i], noteDuration);
      delay(noteDuration * 0.3);
    }
  }
};

#endif