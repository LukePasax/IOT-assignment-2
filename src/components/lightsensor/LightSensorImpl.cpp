#include <Arduino.h>
#include "LightSensorImpl.h"

int LightSensorImpl::getLight(){
int value = analogRead(this->getPin());
  double valueInVolt = ((double) value) * 5/1024;
  //Serial.println(String(value) + " -> in volt: " + valueInVolt );
  return value;
}
