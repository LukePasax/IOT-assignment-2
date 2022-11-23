#include <Arduino.h>
#include "MotorImpl.h"

Motor::Motor(uint8_t pin) {
    this->pin = pin;
    servo.attach(pin);
}

void Motor::autoMove(int angle) {
    servo.write(angle);
}

void Motor::pirMove(int pirValue) {
    int val = map(pirValue, 0, 1023, 0, 180);
    servo.write(val);
}