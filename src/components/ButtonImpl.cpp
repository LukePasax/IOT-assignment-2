#include <Arduino.h>
#include "ButtonImpl.h"

bool ButtonImpl::isPressed() {
  return this->pressed;
}
