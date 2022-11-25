#include <Arduino.h>
#include "LightSensorImpl.h"

int LightSensorImpl::getLight(){
int value = analogRead(this->getPin());
Serial.println(value);
  return value;
}
