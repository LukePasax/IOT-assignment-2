#include <Arduino.h>
#include "SituationTask.h"
#include "StrategyOn.h"
#include "StrategyBlink.h"
#include "StrategyOff.h"
#define PENORMAL 3
#define PEPREALARM 2
#define PEALARM 1

SituationTask::SituationTask(Sonar *s, LedTask *ledCTask, Led *LedB, MotorImpl* motor, LcdTask* lcdTask, LightSystemTask* lst, PotentiometerImpl* pot) {
    this->s = s;
    this->ledCTask = ledCTask;
    this->ledB = LedB;
    this->m = motor;
    this->lcdTask = lcdTask;
    this->ls = lst;
    this->pot = pot;
}

void SituationTask::init(int period){
    Task::init(period);
}

void SituationTask::tick(){
    float distance = s->getDistance(); 
    int situation = getSituation(distance);
    Serial.print(distance);
    Serial.print(", ");
    Serial.println(situation);
    ledCTask->setActive(true);
    
    switch (situation) {
        case PENORMAL:
            ledCTask->setPeriod(500);
            ledCTask->setStrategy(new StrategyOff());
            
            lcdTask->setPrint("");
            ledB->turnOn();
            this->setPeriod(3000);

            break;
        case PEPREALARM:
            this->setPeriod(2000);
            ledCTask->setPeriod(2000);
            ledCTask->setStrategy(new StrategyBlink());
            lcdTask->setPrint("PREALARM " + String(distance));
            lcdTask->setActive(true);
            break;
        case PEALARM:
            ledCTask->setPeriod(500);
            ledB->turnOff();
            ledCTask->setStrategy(new StrategyOn());
            lcdTask->setActive(true);
            ls->setActive(false);
            lcdTask->setPrint("ALARM " + String(distance));
            this->setPeriod(1000);
            ledB->turnOff();
            
            m->potMove(pot->getValue());
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