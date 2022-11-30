#include <Arduino.h>
#include "ButtonImpl.h"
ButtonImpl::ButtonImpl(uint8_t pin, uint8_t mode):Button(pin, mode){
  this->pressed = false;
}
bool ButtonImpl::isPressed() {
  return this->pressed;
}

void ButtonImpl::setPressed(bool pressed) {
  this->pressed = pressed;
}