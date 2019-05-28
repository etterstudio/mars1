int modify_through_serial(int input) {
  // über Serial einen Integer einlesen und dann den input damit anpassen:
  while (Serial.available() > 0) {
    int inChar = Serial.parseInt();
    if (Serial.read() == '\n') {
      input = inChar;
    }
  }
  return input;
}
