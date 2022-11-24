#include <Arduino.h>
#include "StrategyOff.h"

void StrategyOff::execute(int pin){
    if(digitalRead(pin) == HIGH){
        digitalWrite(pin, LOW);
    }
}
