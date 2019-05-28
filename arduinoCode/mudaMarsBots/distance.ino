/*
 * Die Funktion setup_distance() initialisiert alles nötige um den Distanzsensor auszulesen.
 * Die Funktion measure_distance() kann dazu benutzt werden, die Distanz des nächsten Objektes vor dem Sensor auszulesen.
 */
#include <NewPing.h>
 
#define TRIGGER_PIN 8
#define ECHO_PIN A5
#define MAX_DISTANCE 200

// NewPing setup of pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

unsigned long timeNowDistance = millis();
unsigned int distance;

void setup_distance() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

unsigned int measure_distance() {
  /*
   * Liest den Distanz sensor aus und gibt Distanz in Zentimetern zurück.
   */
  int period = 50;
  if(millis() > timeNowDistance + period) {
     distance = sonar.ping_cm();
     //Serial.print(distance);
     //Serial.println("cm");
     timeNowDistance = millis();
  }
  
  return distance;
}
