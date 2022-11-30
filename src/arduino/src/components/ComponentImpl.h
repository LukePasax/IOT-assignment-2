#ifndef __COMPONENTIMPL__
#define __COMPONENTIMPL__
#include <Arduino.h>
#include "Component.h"
class ComponentImpl : public Component {
    public:
        ComponentImpl(uint8_t pin, uint8_t mode);
        uint8_t getPin();
    private:
        uint8_t pin;
        uint8_t mode;
};

#endif