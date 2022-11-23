#include <Arduino.h>
#include "LedTask.h"
#include "StrategyOn.h"
LedTask::LedTask(Led *led) {
    state = false;  
    this->led = led;  
    setStrategy(new StrategyOn());
}

void LedTask::init(int period){
    Task::init(period);
}

void LedTask::getTaskName(){
    Serial.print("LedTask");
}