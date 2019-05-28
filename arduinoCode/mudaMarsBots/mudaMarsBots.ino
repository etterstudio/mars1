
typedef struct{
  signed int x;
  signed int y;
} inputDirection;


void setup() {
  Serial.begin(9600);
  setup_servos();
  setup_color();
  //setup_bluetooth();
  setup_distance();

  for (int i = 8; i <= 12; i++) {
    pinMode(i, OUTPUT);
  }
}

int servoSpeed = 0;

void loop() {
  // Beispiel Programm
  unsigned int distanceMeasured = measure_distance();
  unsigned int scanResult = 0;
  if (distanceMeasured <= 15 && distanceMeasured > 0) {
    scanResult = sense_color();
  }

  if (scanResult == 1) {
    for (int i = 8; i <= 11; i++) {
      digitalWrite(i, 0);
    }
    digitalWrite(12, 1);
  } else if (scanResult == 2) {
    for (int i = 8; i <= 10; i++) {
      digitalWrite(i, 0);
    }
    digitalWrite(11, 1);
    digitalWrite(12, 0);
  }
  else {
    for (int i = 8; i <= 12; i++) {
      digitalWrite(i, 0);
    }
  }

  servoSpeed = modify_through_serial(servoSpeed);

  Serial.println(servoSpeed);

  control_servo(0, servoSpeed);
  control_servo(1, -servoSpeed);
  control_servo(2, servoSpeed);
  control_servo(3, -servoSpeed);
  control_servo(4, -servoSpeed);
  control_servo(5, -servoSpeed);
}

void bluetooth_mode() {
  unsigned int distanceMeasured = measure_distance();
  unsigned int scanResult = 0;
  if (distanceMeasured <= 15 && distanceMeasured > 0) {
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
