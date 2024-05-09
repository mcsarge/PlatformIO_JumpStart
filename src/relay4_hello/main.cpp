#include <Arduino.h>

unsigned long lastPrint = 0;

void setup() {
  
  //Start the console at 9600
  Serial.begin(9600);
}

void loop() {

  //if it has been more that 1 second since the last time...
  if (lastPrint+1000 < millis()){
    Serial.println("Hello World");
    lastPrint = millis();
  }
}
