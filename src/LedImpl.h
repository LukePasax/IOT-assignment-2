#ifndef __LEDIMPL__
#define __LEDIMPL__
#include "ComponentImpl.h"
#include "Led.h"
class LedImpl : public ComponentImpl, public Led {
    public:
        using ComponentImpl::ComponentImpl;
        void turnOn();
        void turnOff();
};

#endif