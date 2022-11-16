#include<Arduino.h>
#include"Component.h"

Component::Component(uint8_t pin, uint8_t mode) {
    this->pin = pin;
    this->mode = mode;
    pinMode(pin, mode);
}
uint8_t Component::getPin(){
    return this->pin;
}