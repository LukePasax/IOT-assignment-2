#ifndef __LEDTASK__
#define __LEDTASK__


#include <Arduino.h>
#include "Task.h"
#include "components/led/LedImpl.h"
#include "strategy/Strategy.h"

class LedTask : public Task {
    public:
        LedTask(Led *led);
        void init(int period);
        void tick();
        void setStrategy(Strategy *strategy);

    private:
        Strategy *strategy;
        Led *led;
};

#endif