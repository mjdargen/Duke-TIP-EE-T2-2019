/*
  8x8 LED Matrix - MAX7219
  * Animations using the LED Matrix
  Michael D'Argenio

  You will need to install the LEDControl Library(not installed by default)
  LEDControl by Eberhard Fahle in Tools -> Manage Libraries
  https://playground.arduino.cc/Main/LedControl/


  You should set up the pins as shown below:
  * Vcc – 5V
  * GND – GND
  * DIN – pin 11
  * CLK – pin 13
  * CS – pin 9
*/

/* Include LEDControl Library */
#include "LedControl.h"

/* we always wait a bit between updates of the display */
#define DELAY 200


/* LedControl(DIN,CLK,CS,# of LED Matrices */
LedControl lc=LedControl(11,13,9,1);

/* Here is the data for the animations
 * 1 corresponds to LED on,
 * 0 corresponds to LED off
 * Each bit represents 1 LED in the 8x8 matrix
*/
byte a[8]={ B00011000,
            B00100100,
            B00100100,
            B00011000,
            B01111110,
            B00011000,
            B00100100,
            B01000010};

byte b[8]={ B00011000,
            B00100100,
            B00100100,
            B00011010,
            B01111100,
            B00011000,
            B01100100,
            B00000010};

byte c[8]={ B00011000,
            B00100100,
            B00100100,
            B00011010,
            B00111100,
            B01011000,
            B00110100,
            B00000100};

byte d[8]={ B00011000,
            B00100100,
            B00100100,
            B00011010,
            B00111100,
            B01011000,
            B00011000,
            B00011000};

byte e[8]={ B00011000,
            B00100100,
            B00100100,
            B00011010,
            B00111100,
            B01011000,
            B00010100,
            B00010000};

byte f[8]={ B00011000,
            B00100100,
            B00100100,
            B00011000,
            B00111110,
            B01011000,
            B00010100,
            B00010100};

void setup() {
  /* The MAX72XX is in power-saving mode on startup, we have to do a wakeup call */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

void loop() { 
  sprites();
}

/*
 This function will display each one of the 
 animations one after the other on the matrix. 
*/
void sprites() {

  /* loop through and display one animation */
  for (int i=0; i<8; i++)
    lc.setRow(0,i,a[i]);
  delay(DELAY); // delay

  /* loop through and display one animation */
  for (int i=0; i<8; i++)
    lc.setRow(0,i,b[i]);
  delay(DELAY);

  /* loop through and display one animation */
  for (int i=0; i<8; i++)
    lc.setRow(0,i,c[i]);
  delay(DELAY);

  /* loop through and display one animation */
  for (int i=0; i<8; i++)
    lc.setRow(0,i,d[i]);
  delay(DELAY);

  /* loop through and display one animation */
  for (int i=0; i<8; i++)
    lc.setRow(0,i,e[i]);
  delay(DELAY);

  /* loop through and display one animation */
  for (int i=0; i<8; i++)
    lc.setRow(0,i,f[i]);
  delay(DELAY);
            
}
