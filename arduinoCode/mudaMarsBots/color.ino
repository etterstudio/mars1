/*
 * Die Funktion setup_distance() initialisiert alles nötige um den Distanzsensor auszulesen.
 * Die Funktion measure_distance() kann dazu benutzt werden, die Distanz des nächsten Objektes vor dem Sensor auszulesen.
 */
#define S0 A0
#define S1 A1
#define S2 A2
#define S3 A3
#define sensorOut A4

int frequency[3];
unsigned long timeNowColor = millis();
uint8_t modeColor = 0;

void setup_color() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  
  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);  
}

int sense_color() {
  int period = 10;
  int scanResult = 0;
  if (modeColor == 0) {
    // Red detection
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
  } else if (modeColor == 1) {
    // Green detection
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
  } else if (modeColor == 2) {
    // Blue detection
    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
  }
  if (millis() >= timeNowColor + period) {
    frequency[modeColor] = pulseIn(sensorOut, LOW);
    modeColor = (modeColor + 1) % 3;
    timeNowColor = millis();
  }
  Serial.print("R is ");
  Serial.print(frequency[0]);
  Serial.print(" G is ");
  Serial.print(frequency[1]);
  Serial.print(" B is ");
  Serial.print(frequency[2]);


  int detectionBound = 500;
  int diffRG = frequency[0] - frequency[1];
  int diffRB = frequency[0] - frequency[2];
  int diffGB = frequency[1] - frequency[2];

  if (diffRG <= -detectionBound && diffRB <= -detectionBound) {
    scanResult = 1;
  } else if (diffRB >= detectionBound && diffGB >= detectionBound) {
    scanResult = 2;
  } else if (diffRG >= detectionBound && diffGB <= -detectionBound) {
    scanResult = 3;
  }

  Serial.print(" Scan result is ");
  Serial.println(scanResult);

  return scanResult;
}
