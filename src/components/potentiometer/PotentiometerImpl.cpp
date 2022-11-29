#include <Arduino.h>
#include "PotentiometerImpl.h"

PotentiometerImpl::PotentiometerImpl(uint8_t pin) {
  this->pin = pin;
}

int PotentiometerImpl::getValue() {
  return map(analogRead(getPin()), 0, 1023, 0, 100);
}

uint8_t PotentiometerImpl::getPin() {
  return pin;
}




