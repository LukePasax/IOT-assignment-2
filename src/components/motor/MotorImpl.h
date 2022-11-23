#ifndef __MOTORIMPL__
#define __MOTORIMPL__

#include <Servo.h>

class MotorImpl : public Servo{
    public:
        MotorImpl(uint8_t pin);
        void autoMove(int angle);
        void potMove(int pirValue);
    
};

#endif