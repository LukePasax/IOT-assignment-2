#include<Arduino.h>
#include"Led.h"

Led::Led(uint8_t pin, uint8_t mode) {
    pinMode(pin, mode);
    this->pin = pin;
}

void Led::turnOn() {
    digitalWrite(getPin(), HIGH);
}

void Led::turnOff() {
    digitalWrite(getPin(), LOW);
}

uint8_t Led::getPin(){
    return this->pin;
}