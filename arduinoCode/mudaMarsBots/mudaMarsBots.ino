void setup() {
  Serial.begin(9600);
  setup_steppers();
  setup_servo();
  setup_color();
}

void loop() {
  //unsigned int distanceMeasured = measure_distance();
  control_servo();
  //sense_color();
}
