#include <Arduino.h>
#include "SituationTask.h"
#include "strategy/StrategyOn.h"
#include "strategy/StrategyBlink.h"
#include "strategy/StrategyOff.h"
#include "Global.h"

SituationTask::SituationTask(Sonar *s, LedTask *ledCTask, LedTask *LedBTask, 
                                MotorImpl* motor, LcdTask* lcdTask,
                                 PotentiometerImpl* pot, ButtonImpl* b) {
    this->s = s;
    this->ledCTask = ledCTask;
    this->ledBTask = LedBTask;
    this->m = motor;
    this->lcdTask = lcdTask;
    this->pot = pot;
    this->b = b;
    this->numListeners=0;
}

void SituationTask::init(int period){
    Task::init(period);
}

void SituationTask::tick(){
    float distance = s->getDistance(); 
    int situation = getSituation(distance);
    Serial.print(distance);
    ledCTask->setActive(true);
    ledBTask->setActive(true);
    switch (situation) {
        case NORMAL:
            Serial.print(" NORMAL ");
            executeNormal();
            break;
        case PREALARM:
            Serial.print(" PREALARM ");
            executePrealarm(distance);
            break;
        case ALARM:
            Serial.print(" ALARM ");
            executeAlarm(distance);
            break;
        default:
            Serial.println("Error");
            break;
    }
    this->notifyListeners(situation);
}

void SituationTask::executeNormal(){
    this->setPeriod(PE_NORMAL);
    ledCTask->setPeriod(500);
    ledCTask->setStrategy(new StrategyOff());
    m->write(0);
    lcdTask->setPrint("", "", "");
    ledBTask->setStrategy(new StrategyOn());
    b->setPressed(false);
}

void SituationTask::executePrealarm(float distance){
    this->setPeriod(PE_PREALARM);
    ledBTask->setStrategy(new StrategyOff());
    m->write(0);
    ledCTask->setPeriod(2000);
    ledCTask->setStrategy(new StrategyBlink());
    lcdTask->setPrint("PREALARM " + String(distance), "", "");
    lcdTask->setActive(true);
    b->setPressed(false);
}

void SituationTask::executeAlarm(float distance){
    this->setPeriod(PE_ALARM);
    ledCTask->setPeriod(500);
    ledBTask->setStrategy(new StrategyOff());
    ledCTask->setStrategy(new StrategyOn());
    lcdTask->setActive(true);
    if (b->isPressed()) {
        int val = pot->getValue();
        lcdTask->setPrint("ALARM " + String(distance), "Valve opened: " + String(val), "MANUAL MODE");
        m->potMove(val);
    } else {
        float val = distance;
        distance = distance*100;
        int a = (int)distance;
        m->autoMove(a);
        lcdTask->setPrint("ALARM " + String(val), "Valve opened: " + String(100 - (a*100/30)), "AUTOMATIC MODE");
    }
}

void SituationTask::addListener(Listener* listener){
    if(numListeners < MAX_LISTENER){
        listeners[numListeners] = listener;
        numListeners++;
    }
};

void SituationTask::notifyListeners(int value){
    for(int i = 0; i < numListeners; i++){
        if(listeners[i] != NULL){
            listeners[i]->notified(value);
        }
    }
};

int SituationTask::getSituation(float distance){
    if(distance < NORMAL_W_LEVEL){
        return 3;
    } else if (distance < PREALARM_W_LEVEL){
        return 2;
    } else {
        return 1;
    }
}