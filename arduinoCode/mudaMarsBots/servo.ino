#include <Servo.h>  //add '<' and '>' before and after servo.h
 
int servoPin = 14;
 
Servo servo;  
  
void setup_servo()
{
  servo.attach(servoPin);
}

void control_servo()
{
  if (Serial.available() > 0) {
    long angle = Serial.parseInt();
    if (Serial.read() == '\n') {
      //analogWrite(servoPin,angle);
      servo.write(angle);
    }
  }
//  analogWrite(servoPin,50);
//  servo.write(angle);
}
