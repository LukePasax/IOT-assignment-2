#include <Arduino.h>
#include "PotentiometerImpl.h"

// return a value between 0 and 100
int PotentiometerImpl::getValue() {
  return map(analogRead(getPin()), 0, 1023, 0, 100);
}

