#include<Arduino.h>
#include"Component.h"

Component::Component(int pin) {
    this->pin = pin;
}

int Component::getPin() {
    return pin;
}