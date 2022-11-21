#include <Arduino.h>
#include "LightSensorImpl.h"

int LightSensorImpl::getLight(){
    int value = analogRead(this->getPin());
    return value;
}
