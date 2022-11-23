#include "Scheduler.h"
#include <TimerOne.h>

volatile bool timerFlag;

void timerHandler(void){
  timerFlag = true;
}

void Scheduler::init(int basePeriod){
  this->basePeriod = basePeriod;
  timerFlag = false;
  long period = 1000l*basePeriod;
  Timer1.initialize(period);
  Timer1.attachInterrupt(timerHandler);
  nTasks = 0;
}

bool Scheduler::addTask(Task* task){
  if (nTasks < MAX_TASKS-1){
    taskList[nTasks] = task;
    nTasks++;
    return true;
  } else {
    return false; 
  }
}
  
void Scheduler::schedule(){ 

  //Serial.println("dentro schedule");
  //Serial.println(timerFlag);
  while (!timerFlag){
  //Serial.println("dentro while");
  }
  timerFlag = false;

    //Serial.println("dopo while, faccio il for");
    //Serial.println(nTasks);
  for (int i = 0; i < nTasks; i++){
    //Serial.println("dentro for");
    if (taskList[i]->isActive() && taskList[i]->updateAndCheckTime(basePeriod)){
      taskList[i]->tick();
      //Serial.println( " is active");
    }
    if (!taskList[i]->isActive()){
      //Serial.println( " is not active");
    }
  }
  //Serial.println("fine");
}

void Scheduler::deactivateAllTasks(){
  for (int i = 0; i < nTasks; i++){
    taskList[i]->setActive(false);
  }
}

