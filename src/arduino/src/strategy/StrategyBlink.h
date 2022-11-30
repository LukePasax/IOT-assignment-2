#ifndef __STRATEGYBLINK__
#define __STRATEGYBLINK__
#include "Strategy.h"
class StrategyBlink: public Strategy {
    public:
        void execute(int pin);

};

#endif