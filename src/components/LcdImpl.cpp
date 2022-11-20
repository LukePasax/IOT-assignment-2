#include<Arduino.h>
#include"LcdImpl.h"

void LcdImpl::turnOn() {
    this->isOn = true;
}

void LcdImpl::turnOff() {
    this->isOn = false;
}

void LcdImpl::print(String str) {
    
}

bool LcdImpl::isActive() {
    return this->isOn;
}