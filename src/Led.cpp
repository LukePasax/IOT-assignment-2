#include"src/Component.cpp"
#include<Arduino.h>


class Led : public Component {
    
        
    public:
        Led(int pin): Component(pin) {
            pinMode(pin, OUTPUT);
        }
        void turnOn() {
            digitalWrite(getPin(), HIGH);
        }
        void turnOff() {
            digitalWrite(getPin(), LOW);
        }
};