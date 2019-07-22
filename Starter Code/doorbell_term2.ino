#include "pitches.h"

#define SPEAKER_PIN 8
#define BUTTON_PIN 2


// Mario
int mario[] = {
  NOTE_E4, NOTE_E4, 0, NOTE_E4, 0, NOTE_C4, NOTE_E4, 0, NOTE_G4, 0, NOTE_G3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int mario_Durations[] = {
  8,8,8,8,8,8,8,8,8,3,8
};


// original
int original[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int original_Durations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

// Mii
int mii[] = {
  NOTE_FS4, 0, NOTE_A4, NOTE_CS5, 0, NOTE_A4, 0, NOTE_FS4, NOTE_D4, NOTE_D4, NOTE_D4, 0, NOTE_D5, NOTE_D5, NOTE_D5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int mii_Durations[] = {
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8
};

void setup() {

  pinMode(BUTTON_PIN, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  
}

void loop() {

  int song_choice = random(0,3);

  if(digitalRead(BUTTON_PIN) == HIGH) {
    delay(100);
    if(digitalRead(BUTTON_PIN) == HIGH) {

      switch(song_choice) {
        case 0:
          play_song(mii,mii_Durations,15,1600);
          break;
        case 1:
          play_song(original,original_Durations,8,1000);
          break;
        case 2:
          play_song(mario,mario_Durations,11,1000);
          break;
      }
   }
  }
  
}

void play_song(int melody[], int noteDurations[], int song_length, int tempo) {

      // iterate over the notes of the melody:
      for (int thisNote = 0; thisNote < song_length; thisNote++) {
    
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = tempo / noteDurations[thisNote];
        tone(SPEAKER_PIN, melody[thisNote], noteDuration);
    
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(SPEAKER_PIN);
    }
}
