#include <Arduino.h>
#include "SituationTask.h"
#include "strategy/StrategyOn.h"
#include "strategy/StrategyBlink.h"
#include "strategy/StrategyOff.h"
#include "Global.h"

SituationTask::SituationTask(Sonar *s, LedTask *ledCTask, Led *LedB, 
                                MotorImpl* motor, LcdTask* lcdTask,
                                 PotentiometerImpl* pot, ButtonImpl* b) {
    this->s = s;
    this->ledCTask = ledCTask;
    this->ledB = LedB;
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
    this->notifyListeners(situation);
    Serial.println(distance);
    ledCTask->setActive(true);
    switch (situation) {
        case NORMAL:
            executeNormal();
            break;
        case PREALARM:
            executePrealarm(distance);
            break;
        case ALARM:
            executeAlarm(distance);
            break;
        default:
            Serial.println("Error");
            break;
    }

}


void SituationTask::executeNormal(){
    this->setPeriod(PE_NORMAL);
    ledCTask->setPeriod(500);
    ledCTask->setStrategy(new StrategyOff());
    m->write(0);
    lcdTask->setPrint("");
    ledB->turnOn();
    b->setPressed(false);
}
void SituationTask::executePrealarm(float distance){
    this->setPeriod(PE_PREALARM);
    ledB->turnOff();
    m->write(0);
    ledCTask->setPeriod(2000);
    ledCTask->setStrategy(new StrategyBlink());
    lcdTask->setPrint("PREALARM " + String(distance));
    lcdTask->setActive(true);
    b->setPressed(false);
}

void SituationTask::executeAlarm(float distance){
    this->setPeriod(PE_ALARM);
    ledCTask->setPeriod(500);
    ledB->turnOff();
    ledCTask->setStrategy(new StrategyOn());
    lcdTask->setActive(true);
    lcdTask->setPrint("ALARM " + String(distance));
    ledB->turnOff();
    //Serial.println("isPressed "+String(b->isPressed()));
    if (b->isPressed()) {
        m->potMove(pot->getValue());
    } else {
        distance = distance*100;
        int a = (int)distance;
        m->autoMove(a);
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