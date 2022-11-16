#include<Arduino.h>
#include"ComponentImpl.h"
#include"Component.h"
ComponentImpl::ComponentImpl(uint8_t pin, uint8_t mode) {
    this->pin = pin;
    this->mode = mode;
    pinMode(pin, mode);
}
uint8_t ComponentImpl::getPin(){
    return this->pin;
}