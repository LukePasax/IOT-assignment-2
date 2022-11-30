#include <Arduino.h>
#include "StrategyOn.h"

void StrategyOn::execute(int pin){
    if(digitalRead(pin) == LOW){
        digitalWrite(pin, HIGH);
    }
}
