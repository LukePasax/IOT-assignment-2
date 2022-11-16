#include <Arduino.h>
#include <EnableInterrupt.h>
#include "Led.h"
#include "LedImpl.h"
Led *led;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led = new LedImpl(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  led->turnOn();
  delay(1000);
  led->turnOff();
  delay(1000);
  Serial.println(led->getPin());
}