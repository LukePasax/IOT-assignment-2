#include <Arduino.h>
#include "ButtonImpl.h"

bool ButtonImpl::isPressed() {
  return this->pressed;
}

/*void ButtonImpl::sync() {
  this->pressed = digitalRead(getPin());
  updateSyncTime(millis());
}*/