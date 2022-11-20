#include <Arduino.h>
#include <EnableInterrupt.h>
#include "components/LedImpl.h"
#include "components/ButtonImpl.h"
#include "Scheduler.h"
#include "LedTask.h"
#include "components/Sonar.h"
#include "SonarTask.h"
#define PE_PREALARM 0.5
#define PE_ALARM 1
Led *ledA;
Led *ledB;
Led *ledC;
Button *button;
Scheduler *sched;
LedTask* ledATask;
LedTask* ledBTask;
LedTask* ledCTask;
Sonar* s;
SonarTask* st;

float distance;

void setup() {
  Serial.begin(9600);
  ledA = new LedImpl(13, OUTPUT);
  ledATask = new LedTask(ledA);
  ledATask-> init(1000);
  ledB = new LedImpl(12, OUTPUT);
  ledBTask = new LedTask(ledB);
  ledBTask-> init(1000);
  ledC = new LedImpl(11, OUTPUT);
  ledCTask = new LedTask(ledC);
  ledCTask-> init(1000);


  sched = new Scheduler();
  sched->init(1000);
  
  ledA->turnOn();

  //sched->addTask(ledATask);
  sched->addTask(ledBTask);
  //sched->addTask(ledCTask);

  s = new Sonar(8, 9);
  st = new SonarTask(s);
  st->init(3000);
  st->setActive(true);
  sched->addTask(st);



}

void loop() {
  // put your main code here, to run repeatedly:
  sched->schedule();
  distance = s->getDistance();

  //normal
  if (distance < PE_PREALARM)
  {
    ledB->turnOn();
    ledC->turnOff();
  } 
  //pre alarm
  else if (distance < PE_ALARM)
  {
  
  } 
  //alarm
  else
  {

  }
  
 
}

