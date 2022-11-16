#ifndef __LED__
#define __LED__

class Led {
    
    public:
        Led(uint8_t pin, uint8_t mode);
        void turnOn();
        void turnOff();
        uint8_t getPin();
    private:
        uint8_t pin;
};

#endif