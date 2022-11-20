#include <Arduino.h>
#include "SonarTask.h"

SonarTask::SonarTask(Sonar *s) {
    this->s = s;
}

void SonarTask::init(int period){
    Task::init(period);
}

void SonarTask::tick(){
    float d = s->getDistance();
    /*
    if(d < 0.5){
        this->setPeriod(1000);
    } else if (d < 1.0){
        this->setPeriod(2000);
    } else {
        this->setPeriod(3000);
    }*/
    Serial.println(d);
}

void SonarTask::getTaskName(){
            Serial.print("SonarTask");
}