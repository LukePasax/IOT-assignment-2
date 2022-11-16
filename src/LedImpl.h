#ifndef __LEDIMPL__
#define __LEDIMPL__
#include "Component.h"
#include "Led.h"
class LedImpl : public Led {
    public:
        using Led::Led;
        void turnOn();
        void turnOff();
        uint8_t getPin();
};

#endif