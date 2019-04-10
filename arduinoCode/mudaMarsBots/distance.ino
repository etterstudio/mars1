/*
 * Posted on https://randomnerdtutorials.com
 * created by http://playground.arduino.cc/Code/NewPing
*/

#include <NewPing.h>
 
#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 200

// NewPing setup of pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

unsigned long timeNow;
unsigned int distance;

unsigned int measure_distance() {
  int period = 50;
  if(millis() > timeNow + period) {
     distance = sonar.ping_cm();
     Serial.print(distance);
     Serial.println("cm");
  }
  
  return distance;
}
