#include <Arduino.h>
#include "SituationTask.h"
#include "StrategyOn.h"
#include "StrategyBlink.h"
#include "StrategyOff.h"
#define PENORMAL 3
#define PEPREALARM 2
#define PEALARM 1

SituationTask::SituationTask(Sonar *s, LedTask *ledCTask, Led *LedB, /*MotorImpl* motor,*/ LcdTask* lcdTask, LightSystemTask* lst, PotentiometerImpl* pot) {
    this->s = s;
    this->ledCTask = ledCTask;
    this->ledB = LedB;
    //this->m = motor;
    this->lcdTask = lcdTask;
    this->ls = lst;
    this->pot = pot;
    Serial.println("SITUATION TASK CREATED");
}

void SituationTask::init(int period){
    Serial.println("task init");
    Task::init(period);
}

void SituationTask::tick(){
    int situation = getSituation(s->getDistance());
    Serial.println(situation);
    switch (situation) {
        case PENORMAL:
            //lc spento
            ledCTask->setStrategy(new StrategyOff());
            lcdTask->setActive(false);
            ledB->turnOn();
            //this->setPeriod(3000);
            break;
        case PEPREALARM:
            //ledCTask->setActive(true);
            //this->setPeriod(2000);
            ledCTask->setActive(true);
            ledCTask->setStrategy(new StrategyBlink());
            lcdTask->setPrint("PREALARM");
            lcdTask->setActive(true);
            break;
        case PEALARM:
            ledB->turnOff();
            ledCTask->setActive(true);
            ledCTask->setStrategy(new StrategyOn());
            lcdTask->setActive(true);
            //ls->setActive(false);
            ledB->turnOff();
            break;
        default:
            Serial.println("Error");
            break;
    }

}

int SituationTask::getSituation(float distance){

    if(distance < 0.5){
        return 3;
    } else if (distance < 1.0){
        return 2;
    } else {
        return 1;
    }
}