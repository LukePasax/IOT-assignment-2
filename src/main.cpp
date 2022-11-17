#include <Arduino.h>
#include <EnableInterrupt.h>
#include "components/LedImpl.h"
#include "components/ButtonImpl.h"

LedImpl *led;
ButtonImpl *button;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led = new LedImpl(8, OUTPUT);
  button = new ButtonImpl(7, INPUT, true);
  Serial.println(button->getPin());
}

void loop() {
  // put your main code here, to run repeatedly:
  led->turnOn();
  delay(1000);
  led->turnOff();
  delay(1000);
  Serial.println(led->getPin());
  Serial.println(button->isPressed());
}