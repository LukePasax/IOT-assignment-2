#ifndef __LEDTASK__
#define __LEDTASK__


#include <Arduino.h>
#include "Task.h"
#include "components/led/LedImpl.h"
#include "Strategy.h"

class LedTask : public Task {
    public:
        LedTask(Led *led);
        void init(int period);
        void tick(){
            strategy->execute(led->getPin());
        };
        //set on or off led
        //void setLedState(bool state);
        void getTaskName();
        void setStrategy(Strategy *strategy){
            this->strategy = strategy;
        };

    private:
        Strategy *strategy;
        bool state;
        Led *led;
};

#endif