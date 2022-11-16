#include<Arduino.h>
#include"LedImpl.h"

void LedImpl::turnOn() {
    digitalWrite(getPin(), HIGH);
}

void LedImpl::turnOff() {
    digitalWrite(getPin(), LOW);
}