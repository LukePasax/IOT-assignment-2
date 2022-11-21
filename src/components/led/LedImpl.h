#ifndef __LEDIMPL__
#define __LEDIMPL__
#include "../ComponentImpl.h"
#include "Led.h"
class LedImpl : public Led{
    public:
        using Led::Led;
        void turnOn();
        void turnOff();
};

#endif