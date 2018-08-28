#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
int serialData = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  motor1.setSpeed(200);     // set the speed to 200/255
  motor2.setSpeed(200);     // set the speed to 200/255
}

void loop() {
  if (Serial.available() > 0)
  {
    serialData = Serial.read();

    switch (serialData) {
         case 49:
           Serial.println("stop");
           motor1.run(RELEASE);      // stopped
           motor2.run(RELEASE);      // stopped
           break;
         case 50:
           Serial.println("Forward");
           motor1.run(BACKWARD);     // the other way
           motor2.run(BACKWARD);     // the other way
           break;
         case 51:
          Serial.println("Back");
           motor1.run(FORWARD);     // the other way
           motor2.run(FORWARD);     // the other way
           break;
         case 52:
          Serial.println("Left");
           motor1.run(FORWARD);     // the other way
           motor2.run(BACKWARD);     // the other way
           break;                      
         case 53:
          Serial.println("Right");
           motor1.run(BACKWARD);     // the other way
           motor2.run(FORWARD);     // the other way
           break;                    
         default: 
           // if nothing else matches, do the default
           // default is optional
                     Serial.println("No Match");
         break;
   }

 }   
}
