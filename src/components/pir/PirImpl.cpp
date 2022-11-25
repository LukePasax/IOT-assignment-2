#include <Arduino.h>
#include "PirImpl.h"

bool PirImpl::isMotionDetected() {
    int read = digitalRead(this->getPin());
    Serial.println(read);
    return read == HIGH;
}