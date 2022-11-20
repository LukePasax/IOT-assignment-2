#include <Arduino.h>
#include "LedTask.h"

LedTask::LedTask(Led *led) {
    state = false;  
    this->led = led;  
}

void LedTask::init(int period){
    Task::init(period);
}

void LedTask::tick(){
    if (state) {
        state = !state;
        led->turnOn();
        //Serial.println("ON");
    } else {
        state = !state;
        led->turnOff();
        //Serial.println("OFF");
    }
}

/*void LedTask::setLedState(bool state) {
    this->state = state;
}*/

void LedTask::getTaskName(){
    Serial.print("LedTask");
}