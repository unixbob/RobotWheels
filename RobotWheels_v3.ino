#include <AFMotor.h>
// setup for a two wheel motor
AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
int serialData = 0;
int Distance = 100;
unsigned long time;

#include "Ultrasonic.h"
// VCC <–> 5V
// Trig <–> D24
// Echo<–> D22
// GND <–>GND
Ultrasonic ultrasonic(24,22);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
  motor1.setSpeed(200);     // set the speed to 200/255
  motor2.setSpeed(200);     // set the speed to 200/255
}

void loop() {
         delay (5000);
  while (time <= 60000)
  {
  time = millis();
  Serial.print("time!");
  Serial.println(time);

  Distance = ultrasonic.Ranging(CM);
    if (Distance > 15)
    {
           // Drive Forward
           motor1.run(BACKWARD);     // the other way
           motor2.run(BACKWARD);     // the other way
     }
     else
     {
  Serial.print("Hit a wall.  Stop the car");
  
        // Hit a wall.  Stop the car
           motor1.run(RELEASE);      // stopped
           motor2.run(RELEASE);      // stopped
           delay (1000);
  Serial.print("Turn Right");
           
        // Turn Right
           motor1.run(BACKWARD);     // the other way
           motor2.run(FORWARD);     // the other way
           delay (1000);
     }
  }
             motor1.run(RELEASE);      // stopped
           motor2.run(RELEASE);      // stopped
}
