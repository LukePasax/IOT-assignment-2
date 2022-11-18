#include <Arduino.h>
#include "Task.h"
#include "components/LedImpl.h"

class MyTask : public Task {
    public:
        MyTask(Led *led);
        void init(int period);
        void tick();
        bool setState(bool state);
    private:
        bool state;
        Led *led;
};