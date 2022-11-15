#ifndef __COMPONENT__
#define __COMPONENT__

class Component {
    private:
        int pin;
    public:
        Component(int pin);
        int getPin();
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
};

#endif