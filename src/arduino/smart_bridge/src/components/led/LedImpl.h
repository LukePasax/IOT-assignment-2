#ifndef __LEDIMPL__
#define __LEDIMPL__

#include "Led.h"
class LedImpl : public Led{
    public:
        using Led::Led;
        void turnOn();
        void turnOff();
};

#endif