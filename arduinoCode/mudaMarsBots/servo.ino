/*
 * Die Funktion setup_servos() initialisiert alles nötige um die Servomotoren anzusteuern.
 * Die Funktion control_servo() kann dazu benutzt werden, einen spezifischen Servo (0-5) anzusteuern.
 */
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
  /*
   * servoNum bezeichnet den gewünschten Servomotor. Mögliche Werte sind 0 bis 5.
   * servoSpeedPercentage bezeichnet die gewünschte Position oder Geschwindigkeit in Prozent. Mögliche Werte sind -100 bis 100.
   */
  int servoSpeed = servoSpeedPercentage*0.5 + 90;
  servos[servoNum].write(servoSpeed);
}
