#include <Arduino.h>
#include "LightSensorImpl.h"

float LightSensorImpl::getLight(int pin){
    float t = analogRead(A0);
    //1023 : 5000 = x : 1700
    float a = 1023.0 * 1700.0 / 5000.0;
    //float a = 347.82;
    float cel = 166 * t / a;
    Serial.println(cel-40);
    float res = cel - 40;
    return res;
}