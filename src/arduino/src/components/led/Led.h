#ifndef __LED__
#define __LED__

#include "../ComponentImpl.h"

class Led : public ComponentImpl{
    public:
        using ComponentImpl::ComponentImpl;
        virtual void turnOn();
        virtual void turnOff();
};

#endif