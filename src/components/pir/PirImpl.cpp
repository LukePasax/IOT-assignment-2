#include <Arduino.h>
#include "PirImpl.h"

void PirImpl::detectMove() {
    int val = digitalRead(this->getPin());
    if (val == HIGH) {
        Serial.println("Motion detected!"); 
        motionDetected = true;
    }     
    else {    
        Serial.println("Motion stopped!");
        motionDetected = false;
    }
}