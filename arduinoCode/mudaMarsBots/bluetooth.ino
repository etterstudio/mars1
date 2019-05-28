/*
 * Die Funktion setup_bluetooth() initialisiert alles nötige um Daten über Bluetooth auszulesen.
 * Die Funktion read_bluetooth() kann dazu benutzt werden, die Richtung die von einem Handy vorgegeben wird auszulesen.
 */
#include <SoftwareSerial.h>

#define TxD 1
#define RxD 0

SoftwareSerial hc06(RxD, TxD);
unsigned long timeNowBluetooth = millis();
int xInput = 140;
int yInput = 140;

void setup_bluetooth() {
  hc06.begin(9600);
}


inputDirection read_bluetooth() {
  /*
   * Liest daten vom Bluetooth Modul kommend aus, und skaliert sie zu Werten von -100 bis 100.
   */
  inputDirection input;
  int readDelay = 10;

  
  while (hc06.available() >= 2) {
      xInput = hc06.read();
      yInput = hc06.read();
    }

  if (xInput > 60 & xInput < 220) {
    input.x = map(xInput, 220, 60, 100, -100);
  }
  if (yInput > 60 & yInput < 220) {
    input.y = map(yInput, 220, 60, -100, 100);
  }

  return input;
}
