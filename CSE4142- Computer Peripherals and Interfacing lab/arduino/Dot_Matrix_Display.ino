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
  // Define the pattern for the letter 'A'
  lc.setRow(0, 0, B00000000); // Row 1
  lc.setRow(0, 1, B00111110); // Row 2
  lc.setRow(0, 2, B00100000); // Row 3
  lc.setRow(0, 3, B00100000); // Row 4
  lc.setRow(0, 4, B00111100); // Row 5
  lc.setRow(0, 5, B00100000); // Row 6
  lc.setRow(0, 6, B00100000); // Row 7
  lc.setRow(0, 7, B00100000); // Row 8

  delay(1000); // Update the display every second
}
