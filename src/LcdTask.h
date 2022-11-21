#include <Arduino.h>
#include "Task.h"

class LcdTask : public Task {
    public:
        LcdTask(LiquidCrystal_I2C *lcd);
        void init(int period);
        void tick();
        void setPrint(String print);

    private:
        LiquidCrystal_I2C *lcd;
        String print;
};
