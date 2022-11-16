#ifndef __LED__
#define __LED__
#include "Component.h"
class Led : public Component {
    public:
        using Component::Component;
        virtual void turnOn();
        virtual void turnOff();
};

#endif