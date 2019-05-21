#include <Servo.h> 
/*
int servoPin0 = 2;
int servoPin1 = 3;
int servoPin2 = 4;
int servoPin3 = 5;
int servoPin4 = 6;
int servoPin5 = 7;
*/
int firstServoPin = 2;
Servo servos[6];  
  
void setup_servos()
{
  for (int i = 0; i < 6; i++) {
    servos[i].attach(i + firstServoPin);
  }
}

void control_servo(int servoNum, int servoSpeedPercentage){
  int servoSpeed = servoSpeedPercentage*0.5 + 90;
  servos[servoNum].write(servoSpeed);
}
