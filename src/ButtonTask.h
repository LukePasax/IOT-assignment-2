#ifndef __BUTTONTASK__
#define __BUTTONTASK__

#include "components/button/ButtonImpl.h"
#include "Task.h"

class ButtonTask : public Task {
    public:
        ButtonTask(ButtonImpl *b);
        void init(int period);
        void tick();

    private:
        ButtonImpl *b;
};

#endif