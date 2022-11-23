#include <Arduino.h>
#include "SituationTask.h"
#define PENORMAL 3000
#define PEPREALARM 2000
#define PEALARM 1000

SituationTask::SituationTask(Sonar *s, LedTask *ledCTask, Led *LedB, Led *LedC, MotorImpl* motor, LcdTask* lcdTask, LightSystemTask* lst, PotentiometerImpl* pot) {
    this->s = s;
    this->ledCTask = ledCTask;
    this->ledB = LedB;
    this->ledC = LedC;
    this->m = motor;
    this->lcdTask = lcdTask;
    this->ls = lst;
    this->pot = pot;
}

void SituationTask::init(int period){
    Task::init(period);
}

void SituationTask::tick(){
    int situation = getSituation(s->getDistance());
    Serial.println(situation);
    switch (situation) {
        case PENORMAL:
            ledCTask->setActive(false);
            lcdTask->setActive(false);
            ledB->turnOn();
            ledC->turnOff();
            this->setPeriod(PENORMAL);
            break;
        case PEPREALARM:
            ledCTask->setActive(true);
            this->setPeriod(PEPREALARM);
            lcdTask->setPrint("PREALARM");
            lcdTask->setActive(true);
            break;
        case PEALARM:
            ledCTask->setActive(false);
            lcdTask->setActive(true);
            ls->setActive(false);
            ledB->turnOff();
            ledC->turnOn();
            break;
        default:
            Serial.println("Error");
            break;


    }

}

int SituationTask::getSituation(float distance){

    if(distance < 0.5){
        return 1;
    } else if (distance < 1.0){
        return 2;
    } else {
        return 3;
    }
}