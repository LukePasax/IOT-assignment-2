#ifndef __LCD__
#define __LCD__

#include "ComponentImpl.h"
class Lcd : public ComponentImpl{
    public:
        using ComponentImpl::ComponentImpl;
        virtual void turnOn();
        virtual void turnOff();
        virtual void print(String str);
        virtual bool isActive();
};

#endif