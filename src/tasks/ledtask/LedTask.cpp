#include <Arduino.h>
#include "LedTask.h"
#include "strategy/StrategyOn.h"
LedTask::LedTask(Led *led) { 
    this->led = led;  
    setStrategy(new StrategyOn());
}

void LedTask::init(int period){
    Task::init(period);
}

void LedTask::tick(){
    strategy->execute(led->getPin());
};

void LedTask::setStrategy(Strategy *strategy){
    this->strategy = strategy;
};

int LedTask::getPin(){
    return led->getPin();
}