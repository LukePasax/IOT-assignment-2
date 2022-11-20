#ifndef __LCDIMPL__
#define __LCDIMPL__

#include "Lcd.h"

class LcdImpl: public Lcd {
    public:
        void turnOn();
        void turnOff();
        void print(String str);
        bool isActive();
    private:
        bool isOn;
};
#endif