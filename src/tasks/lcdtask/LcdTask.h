#ifndef __LCDTASK__
#define __LCDTASK__

#include <LiquidCrystal_I2C.h>

class LcdTask : public Task {
    public:
        LcdTask();
        void init(int period);
        void tick();
        void setPrint(String print1, String print2, String print3);
        void getTaskName();

    private:
        LiquidCrystal_I2C *lcd;
        String print1;
        String print2;
        String print3;
};

#endif