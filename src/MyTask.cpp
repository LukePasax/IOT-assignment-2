#include <Arduino.h>
#include "MyTask.h"

MyTask::MyTask(Led *led) {
    state = false;  
    this->led = led;  
}

void MyTask::init(int period){
    Task::init(period);
}

void MyTask::tick(){
    if (state) {
        state = !state;
        led->turnOn();
        Serial.println("ON");
    } else {
        state = !state;
        led->turnOff();
        Serial.println("OFF");
    }
}

void MyTask::setLedState(bool state) {
    this->state = state;
}
