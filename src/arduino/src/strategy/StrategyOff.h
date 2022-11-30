#ifndef __STRATEGYOFF__
#define __STRATEGYOFF__
#include "Strategy.h"
class StrategyOff: public Strategy {
    public:
        void execute(int pin);

};

#endif