#include <Arduino.h>
#include "MotorImpl.h"

MotorImpl::MotorImpl(uint8_t pin) {
    this->attach(pin);
}

void MotorImpl::autoMove(int angle) {
    int val = angle;
    val = map(val, 0, 50, 0, 180);
    this->write(angle);
}

void MotorImpl::potMove(int potValue) {
    int val = potValue;
    val = map(val, 0, 100, 0, 180);
    this->write(val);
    delay(15);
}