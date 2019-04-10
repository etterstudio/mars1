#include <AccelStepper.h>
// Motor pin definitions
#define motorPin1  8     //  A2 
#define motorPin2  9     //  A1
#define motorPin3  10     // B1
#define motorPin4  11     // B2

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
//AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

AccelStepper stepper1 (AccelStepper::HALF4WIRE, motorPin2, motorPin1, motorPin3, motorPin4, true);

// Global variables
long serialRelativeTarget = 0;

void setup_steppers() {
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(50.0);
}

void run_stepper() {

  if (Serial.available() > 0) {
    long relativeTarget = Serial.parseInt();
    if (Serial.read() == '\n') {
//      serialRelativeTarget = relativeTarget;
      stepper1.setSpeed(relativeTarget);
    }
  }
  // run forward if relativeTarget positive and vice versa
//  if (abs(serialRelativeTarget) > 0) {
//    stepper1.move(serialRelativeTarget);
//  } else {
//    stepper1.move(0);
//  }
  stepper1.runSpeed();
}
