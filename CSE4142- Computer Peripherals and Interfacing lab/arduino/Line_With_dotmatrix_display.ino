#include <LedControl.h>

int DIN = 2; 
int CS = 3;
int CLK = 4;

LedControl lc = LedControl(DIN, CLK, CS, 0);

void setup() {
  lc.shutdown(0, false);      // The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0, 15);     // Set the brightness to maximum value
  lc.clearDisplay(0);         // Clear the display
}

void loop() {
  for (int col = 0; col < 8; col++) {
    lc.setColumn(0, col, B11111111); // Turn on all LEDs in the column //for row change the function lc.setRow
    delay(2000);                     // Wait for 2 seconds
    lc.setColumn(0, col, B00000000); // Turn off all LEDs in the column before moving to the next //for row change the function lc.setRow
  }
}
