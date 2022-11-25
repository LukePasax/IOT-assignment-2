#include <Arduino.h>
#include "LightSystemTask.h"
#include "global.h"

LightSystemTask::LightSystemTask(Led *led, PirImpl *pir, LightSensor *lightSensor) {
    this->led = led;
    this->pir = pir;
    this->lightSensor = lightSensor;
}

void LightSystemTask::init(int period) {
    Task::init(period);
    state = false;
}

void LightSystemTask::tick() {
    if (pir->isMotionDetected() && lightSensor->getLight() < LIGHTLEVEL) {
        led->turnOn();
    } else {
        led->turnOff();
    }
}

void LightSystemTask::getTaskName() {
    Serial.println("LightSystemTask");
}

void LightSystemTask::notified(int notify) {
    //Serial.println("LightSystemTask notified");
    notification = notify;
    if(notify == PEALARM){
        led->turnOff();
        this->setActive(false);
    }else{
        this->setActive(true);
    }
}

