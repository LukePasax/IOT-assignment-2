#include <Arduino.h>
#include "Task.h"
#include "components/LedImpl.h"

class LedTask : public Task {
    public:
        LedTask(Led *led);
        void init(int period);
        void tick();
        //set on or off led
        //void setLedState(bool state);
        void getTaskName();

    private:
        bool state;
        Led *led;
};
