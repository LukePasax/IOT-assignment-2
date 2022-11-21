#ifndef __LIGHTSENSOR__
#define __LIGHTSENSOR__

class LightSensor{
    public:
        virtual float getLight(int pin);
};

#endif