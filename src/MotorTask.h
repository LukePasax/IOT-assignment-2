#ifndef __MOTORTASK__
#define __MOTORTASK__

#include "Task.h"

class MotorTask : public Task {
    public:
        void init(int period);
        void tick();
};

#endif