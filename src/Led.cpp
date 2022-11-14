#include"src/Component.cpp"
#include<Arduino.h>


class Led : public Component {
    private:
        int pin;
    public:
        void turnOn() {
            digitalWrite(pin, HIGH);
        }
        void turnOff() {
            digitalWrite(pin, LOW);
        }
};