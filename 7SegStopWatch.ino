#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

unsigned long lastMillis = 0;
unsigned int totalMinutes = 0;   

void setup() {
  display.setBrightness(0x0f);   
}

void loop() {
  
  if (millis() - lastMillis >= 60000) {
    lastMillis += 60000;
    totalMinutes++;

    if (totalMinutes >= 100 * 60) {
      totalMinutes = 0;
    }
  }

  int hours = totalMinutes / 60;
  int minutes = totalMinutes % 60;

  display.showNumberDecEx(
    hours * 100 + minutes,
    0b01000000,   // Colon ON
    true
  );
}
