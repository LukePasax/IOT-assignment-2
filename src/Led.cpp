#include"src/Component.cpp"
#include<Arduino.h>


class Led : public Component {
    public:
        void turnOn() {
            digitalWrite(getPin(), HIGH);
        }
        void turnOff() {
            digitalWrite(getPin(), LOW);
        }
};