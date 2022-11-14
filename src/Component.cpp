class Component {
    private:
        int pin;
    public:
        Component(int pin) {
            this->pin = pin;
        }
        int getPin() {
            return pin;
        }
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
};
