#ifndef __COMPONENTIMPL__
#define __COMPONENTIMPL__
#include "stdio.h"
#include "Component.h"
class ComponentImpl : public Component {
    
    public:
        using Component::Component;
        uint8_t getPin();
};

#endif