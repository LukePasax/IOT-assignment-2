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
    ledCTask->setActive(true);
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
    this->notifyListeners(situation);
    
    //Serial.println(digitalRead(ledCTask->getLed()->getPin()));
    ledCTask->setActive(true);
    switch (situation) {
        case PENORMAL:
            executeNormal();
            break;
        case PEPREALARM:
            executePrealarm(distance);
            break;
        case PEALARM:
            
            executeAlarm(distance);
            break;
        default:
            Serial.println("Error");
            break;
    }

}


void SituationTask::executeNormal(){
    ledCTask->setActive(true);
    ledCTask->setPeriod(500);
    ledCTask->setStrategy(new StrategyOff());
    //ledCTask->getLed()->turnOff();
    m->write(0);
    lcdTask->setPrint("");
    ledB->turnOn();
    this->setPeriod(3000);
    b->setPressed(false);
}
void SituationTask::executePrealarm(float distance){
ledCTask->setActive(true);
    ledB->turnOff();
    m->write(0);
    this->setPeriod(2000);
    /*if (digitalRead(ledCTask->getLed()->getPin())){
        ledCTask->getLed()->turnOff();
    } else {
        ledCTask->getLed()->turnOn();
    }*/
    ledCTask->setPeriod(2000);
    ledCTask->setStrategy(new StrategyBlink());
    lcdTask->setPrint("PREALARM " + String(distance));
    lcdTask->setActive(true);
    b->setPressed(false);
}

void SituationTask::executeAlarm(float distance){
ledCTask->setActive(true);
    this->setPeriod(1000);
    ledCTask->setPeriod(500);
    ledB->turnOff();
    //ledCTask->getLed()->turnOn();
    ledCTask->setStrategy(new StrategyOn());
    lcdTask->setActive(true);
    lcdTask->setPrint("ALARM " + String(distance));
    ledB->turnOff();
    Serial.println("isPressed "+String(b->isPressed()));
    if (b->isPressed()) {
                m->potMove(pot->getValue());
            } else {
                distance = distance*100;
                int a = (int)distance;
                m->autoMove(a);
                Serial.println("autoMove");
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