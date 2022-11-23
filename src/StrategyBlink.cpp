#include <Arduino.h>
#include "StrategyBlink.h"

void StrategyBlink::execute(int pin){
    if(digitalRead(pin) == HIGH){
        digitalWrite(pin, LOW);
    } else {
        digitalWrite(pin, HIGH);
    }
}
