#define S0 6
#define S1 7
#define S2 8
#define S3 9
#define sensorOut 10

int frequency = 0;

void setup_color() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  
  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);  
}

void sense_color() {
  int time_delay = 10;

  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
 
  int frequencyR = pulseIn(sensorOut, LOW);

  delay(time_delay);
  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  int frequencyG = pulseIn(sensorOut, LOW);
 

  delay(time_delay);
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
 
  int frequencyB = pulseIn(sensorOut, LOW);
  
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(100);
}
