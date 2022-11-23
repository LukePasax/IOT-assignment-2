#include <Arduino.h>
#include "MotorImpl.h"

MotorImpl::MotorImpl(uint8_t pin) {
    this->pin = pin;
    servo.attach(pin);
}

void MotorImpl::autoMove(int angle) {
    servo.write(angle);
}

void MotorImpl::pirMove(int pirValue) {
    int val = map(pirValue, 0, 100, 0, 180);
    Serial.println(val);
    servo.write(val);
}