#include<Arduino.h>
#include"Led.h"

Led::Led(int pin) : Component(pin) {
    pinMode(pin, OUTPUT);
}

void Led::turnOn() {
    digitalWrite(getPin(), HIGH);
}

void Led::turnOff() {
    digitalWrite(getPin(), LOW);
}