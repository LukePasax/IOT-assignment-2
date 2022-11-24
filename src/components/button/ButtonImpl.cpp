#include <Arduino.h>
#include "ButtonImpl.h"

bool ButtonImpl::isPressed() {
  return this->pressed;
}

void ButtonImpl::setPressed(bool pressed) {
  this->pressed = pressed;
}