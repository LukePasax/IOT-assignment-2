#ifndef __COMPONENT__
#define __COMPONENT__
class Component {
    public:
        Component(uint8_t pin, uint8_t mode);
        virtual uint8_t getPin();
    private:
        uint8_t pin;
        uint8_t mode;
};

#endif