#include <Arduino.h>
#include "LightSystemTask.h"
#include "global.h"

LightSystemTask::LightSystemTask(Led *led, PirImpl *pir, LightSensor *lightSensor) {
    this->led = led;
    this->pir = pir;
    this->lightSensor = lightSensor;
    time = 0;
}

void LightSystemTask::init(int period) {
    Task::init(period);
    lightTurnedOn = false;
}

void LightSystemTask::tick() {

    if (!lightTurnedOn && pir->isMotionDetected() && lightSensor->getLight() < LIGHTLEVEL) {
        led->turnOn();
        lightTurnedOn = true;
        time = millis();
        Serial.println("Turned on");
    } else if (lightTurnedOn && ((!pir->isMotionDetected() && millis() - time < 4000) || lightSensor->getLight() > LIGHTLEVEL)) {
        led->turnOff();
        lightTurnedOn = false;
        Serial.println("Turned off");
    }
    /*else if (millis() - time > 4000 && lightTurnedOn) {
        lightTurnedOn = false;
        led->turnOff();
    }*/
    
}

void LightSystemTask::getTaskName() {
    Serial.println("LightSystemTask");
}

void LightSystemTask::notified(int notify) {
    notification = notify;
    if(notify == PEALARM){
        lightTurnedOn = false;
        led->turnOff();
        this->setActive(false);
    }else{
        this->setActive(true);
    }
}
