/* 
  Continuous Rotation Servo
  * Illustrates how to use Continuous Rotation Servo
  Michael D'Argenio
  Parallax Continuous Rotation Servo (#900-00008)

  ** Continuous rotation servos require calibration. **
  In order to calibrate, call servo_stop() function on the servo. While 
  servo_stop() is  executing, the servo should not be moving. Use a 
  small phillips head   screwdriver to adjust the small screw at the 
  top of the servo until the servo stops spinning.

  servo.write(angle)
  On a continuous rotation servo, this will set the speed of the servo
  (with 0 being full-speed in one direction, 180 being full speed in 
  the other, and a value near 90 being no movement). 
  * Clockwise: 0 (max CW speed, increases speed from 90->0)
  * Stop: 90
  * Counter-clockwise: 180 (max CCW speed, increases speed from 90->180)

  servo.writeMicroseconds(us)
  Continuous-rotation servos will respond to the writeMicroseconds 
  function in an analogous manner to the write function.
  * Clockwise: 1300 (max CW speed, increases speed from 1500->1300)
  * Stop: 1500
  * Counter-clockwise: 1700 (max CCW speed, increases speed from 1500->1700)
  
*/

#include <Servo.h>

Servo servo1;  // create servo object to control a servo

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
    ; // wait for serial port to connect. Needed for native USB port only

  servo1.attach(9);  // attaches the servo on pin 9 to the servo object

  // send an intro:
  Serial.println("Servo program is loaded");
  Serial.println();
}

void loop() {
  slow_CW(servo1);
  delay(2000);
  med_CW(servo1);
  delay(2000);
  fast_CW(servo1);
  delay(2000);
  stop_servo(servo1);
  delay(2000);
  slow_CCW(servo1);
  delay(2000);
  med_CCW(servo1);
  delay(2000);
  fast_CCW(servo1);
  delay(2000);
  stop_servo(servo1);
  delay(2000);
}

/* moves continuous servo motor in clockwise direction at slow rate */
void slow_CW(Servo myservo) {
  myservo.write(85);
}

/* moves continuous servo motor in clockwise direction at medium rate */
void med_CW(Servo myservo) {
  myservo.write(80);
}

/* moves continuous servo motor in clockwise direction at fast rate */
void fast_CW(Servo myservo) {
  myservo.write(0);
}

/* moves continuous servo motor in counter-clockwise direction at slow rate */
void slow_CCW(Servo myservo) {
  myservo.write(95);
}

/* moves continuous servo motor in counter-clockwise direction at medium rate */
void med_CCW(Servo myservo) {
  myservo.write(100);
}

/* moves continuous servo motor in counter-clockwise direction at fast rate */
void fast_CCW(Servo myservo) {
  myservo.write(180);
}

/* stops continuous rotation servo motor */
void stop_servo(Servo myservo) {
  myservo.write(90);
}

/* adjusts speed and direction of servo across full scale */
/* can also be used for standard servos */
void full_scale(Servo myservo) {
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);                 // tell servo to go to position in variable 'pos'
    delay(20);                          // waits 20ms
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);                 // tell servo to go to position in variable 'pos'
    delay(20);                          // waits 20ms
  }
}
