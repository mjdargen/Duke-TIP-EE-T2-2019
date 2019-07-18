/*
  Palindromes
  * Tells user whether or not a word is a palindrome
  * Uses USB serial interface with computer
  Michael D'Argenio

*/

//#include <stdio.h>

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  Serial.println("Palindrome program is loaded");
  Serial.println();
}

void loop() {

  /* initialize variable */
  String input = "";
  String reversed = "";
  int word_length = 0;
  int match = true;

  /* get any incoming bytes: */
  if (Serial.available() > 0) {
    input = Serial.readString();

    /* get the length of the input string*/
    word_length = input.length();
    
    /* reverse the input and store for comparison */
    for (int i=0; i < word_length; i++) {
      reversed = reversed + input.charAt(word_length-1-i);
    }

    /* compare the input forwards and backwards */
    for (int i=0; i < word_length; i++) {
      if (input.charAt(i) != reversed.charAt(i)) {
          match = false;  // if it doesn't match, change match flag to false
          break;  // "break" ends the loop because we already know it doesn't match
      }
    }

    /* tell user whether or not it was a palindrome */
    Serial.print(input);
    if (match == true)
      Serial.println(" is a palindrome");
    else if (match == false)
      Serial.println(" is not a palindrome");
    
    /* reinitialize variable */
    match = true;
    
  }
}
