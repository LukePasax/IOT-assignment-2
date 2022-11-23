#ifndef __LCDTASK__
#define __LCDTASK__

#include <LiquidCrystal_I2C.h>

class LcdTask : public Task {
    public:
        LcdTask();
        void init(int period);
        void tick();
        void setPrint(String print);
        void getTaskName();

    private:
        LiquidCrystal_I2C *lcd;
        String print;
};

#endif