#ifndef __LED__
#define __LED__
#include "Component.h"

class Led : public Component {
    
    public:
        Led(int pin);
        void turnOn();
        void turnOff();
};

#endif