
typedef struct{
  signed int x;
  signed int y;
} inputDirection;


void setup() {
  Serial.begin(9600);
  setup_steppers();
  setup_servos();
  setup_color();
  setup_bluetooth();
  setup_distance();

  for (int i = 8; i <= 12; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  unsigned int distanceMeasured = measure_distance();
  unsigned int scanResult = 0;
  if (distanceMeasured <= 5 && distanceMeasured > 0) {
    scanResult = sense_color();
  }

  if (scanResult == 1) {
    for (int i = 8; i <= 11; i++) {
      digitalWrite(i, 0);
    }
    digitalWrite(12, 1);
  } else{
    for (int i = 8; i <= 12; i++) {
      digitalWrite(i, 0);
    }
  }
  
  inputDirection bluetoothInput = read_bluetooth();

  int speedServoLeft  = max(min(bluetoothInput.y - bluetoothInput.x/2, 100), -100);
  int speedServoRight  = max(min(bluetoothInput.y + bluetoothInput.x/2, 100), -100);

  control_servo(0, speedServoLeft);
  control_servo(1, speedServoLeft);
  control_servo(2, -speedServoRight);
  control_servo(3, -speedServoRight );
}
