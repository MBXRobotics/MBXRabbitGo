 
#ifndef MBX_MELODY_H
#define MBX_MELODY_H

#include <Arduino.h>
#include "pitchesX.h"

#define BUZZER_PIN 16

// ------------------------------------- Baby Shark melody----------------------------------
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

// -----------------------------------------------------------Happy birthday melody----------------------------------------------
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

// --------------------------------------------------Basic buzzer functions----------------------------------------
void playTone(int frequency, int duration) {
  if (frequency == 0 || frequency == REST) {
    noTone(BUZZER_PIN);
    delay(duration);
  } else {
    tone(BUZZER_PIN, frequency);
    delay(duration);
    noTone(BUZZER_PIN);
  }
}

void stopTone() {
  noTone(BUZZER_PIN);
}

// Success sound
void uploadDone() {
  playTone(NOTE_C4, 150);
  playTone(NOTE_G3, 150);
  playTone(NOTE_G3, 150);
  playTone(NOTE_C4, 150);
  playTone(NOTE_G4, 150);
  playTone(NOTE_C5, 300);
}

// Party sound
void playPartty() {
  for (int freq = 2000; freq > 200; freq -= 50) {
    playTone(freq, 10);
  }
}
// Glide effect helper
void glide(int startFreq, int endFreq, int duration) {
  int steps = 50;
  int stepDelay = duration / steps;
  int freqStep = (endFreq - startFreq) / steps;
  
  for (int i = 0; i <= steps; i++) {
    int currentFreq = startFreq + (freqStep * i);
    tone(BUZZER_PIN, currentFreq);
    delay(stepDelay);
  }
  
  noTone(BUZZER_PIN);
}
// Spaceship sound
void playSpaceshipSound() {
  for (int i = 0; i < 3; i++) {
    glide(100, 1000, 200);
    glide(1000, 100, 200);
  }
}



// -------------------------------------------------------------Police siren------------------------------------------------------
void playPoliceSiren() {
  for (int cycle = 0; cycle < 4; cycle++) {
    for (int freq = 600; freq <= 1200; freq += 15) {
      tone(BUZZER_PIN, freq);
      delay(4);
    }
    delay(50);
    for (int freq = 1200; freq >= 600; freq -= 15) {
      tone(BUZZER_PIN, freq);
      delay(4);
    }
    delay(50);
  }
  
  noTone(BUZZER_PIN);
}

// ------------------------------------------------------Simple beep---------------------------------------------------------------------
void beep() {
  tone(BUZZER_PIN, 500, 100);
  delay(100);
  delay(200);
}

// -----------------------------------------------------Generic song player helper---------------------------------------------------

void playSong(const int* melody, const int* durations, int length, int tempo) {
  for (int i = 0; i < length; i++) {
    int noteDuration = (60000 / tempo) * (4.0 / durations[i]);
    playTone(melody[i], noteDuration);
    delay(noteDuration * 0.3);
  }
}

// -----------------------------------------------------Baby Shark song---------------------------------------------------------------------
void playBabyShark() {
  playSong(babyShark_melody, babyShark_durations, 
           sizeof(babyShark_melody)/sizeof(int), 200);
}

// ------------------------------------------------------Happy Birthday song--------------------------------------------------------------
void playHappyBirthday() {
  playSong(ifYoureHappy_melody, ifYoureHappy_durations, 
           sizeof(ifYoureHappy_melody)/sizeof(int), 180);
}

#endif