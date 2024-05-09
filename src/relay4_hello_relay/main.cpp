#include <Arduino.h>

#define LED_PIN     25

unsigned long lastPrint = 0;
int whichRelay = 0;
bool currentValue = true;

//An array holding the relay pins.
int relays[] = {21,19,18,5};

void setup()
{
    Serial.begin(9600);
    //Set the pins to putput and turn off the relays.
    for (int r=0; r<4; r++){
        pinMode(relays[r], OUTPUT);
        digitalWrite(relays[r], LOW);
    }
    //Initialize the LED
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
}

void loop() {
  //if it has been more that 1 second since the last time...
  if (lastPrint+1000 < millis()){
    Serial.println("Hello World");

    //Set the relay off or on
    digitalWrite(relays[whichRelay++], currentValue);

    //Once we have done all 4, start at 1 again with the new value
    if (whichRelay>3){
      whichRelay = 0;
      currentValue = !currentValue;
      //Update the LED.
      digitalWrite(LED_PIN, currentValue);
    }
    lastPrint = millis();
  }
}
