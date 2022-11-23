#include <Arduino.h>
#include "PotentiometerImpl.h"

PotentiometerImpl::PotentiometerImpl(uint8_t pin) {
  this->pin = pin;
}

// return a value between 0 and 100
int PotentiometerImpl::getValue() {
  return map(analogRead(getPin()), 0, 1023, 0, 100);
}

uint8_t PotentiometerImpl::getPin() {
  return pin;
}




