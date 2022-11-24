#include <Arduino.h>
#include "MotorImpl.h"
#include "Global.h"

MotorImpl::MotorImpl(uint8_t pin) {
    this->attach(pin);
}

void MotorImpl::autoMove(int angle) {
    int val = angle;
    float val2 = NORMAL_W_LEVEL*100;
    val = map(val, 0, (int)val2, 0, 180);
    this->write(val);
}

void MotorImpl::potMove(int potValue) {
    int val = potValue;
    val = map(val, 0, 100, 0, 180);
    this->write(val);
}