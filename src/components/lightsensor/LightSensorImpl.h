#ifndef __LIGHTSENSORIMPL__
#define __LIGHTSENSORIMPL__

#include "LightSensor.h"

class LightSensorImpl : public LightSensor{
    public:
        float getLight(int pin);
};

#endif