#include <Arduino.h>
#include "SituationTask.h"
#define PENORMAL 3000
#define PEPREALARM 2000
#define PEALARM 1000
SituationTask::SituationTask(Sonar *s, LedTask *ledCTask, Led *LedB, Led *LedC, Motor* motor, LightSystemTask* ls, LcdTask* lcdTask, PotentiometerImpl* pot) {
    this->s = s;
    this->ledCTask = ledCTask;
    this->ledB = ledB;
    this->ledC = ledC;
    this->m = motor;
    this->ls = ls;
    this->lcdTask = lcdTask;
    this->pot = pot;
}

void SituationTask::init(int period){
    Task::init(period);
}

void SituationTask::tick(){
    int situation = getSituation(s->getDistance());
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
        case PEALARM:
            ledCTask->setActive(false);
            lcdTask->setActive(true);
            ls->setActive(false);
            ledB->turnOff();
            ledC->turnOn();

    }

}

int getSituation(float distance){
    if(distance < 0.5){
        return 1;
    } else if (distance < 1.0){
        return 2;
    } else {
        return 3;
    }
}