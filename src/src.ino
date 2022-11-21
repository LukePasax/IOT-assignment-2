#include <Arduino.h>
#include <EnableInterrupt.h>
#include "components/LedImpl.h"
#include "components/ButtonImpl.h"
#include "Scheduler.h"
#include "LedTask.h"
#include "components/Sonar.h"
#include "SonarTask.h"
#include "LcdTask.h"
#include <LiquidCrystal_I2C.h>
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
LcdTask* lcdTask;
Sonar* s;
SonarTask* st;


float distance;

//tutte le task nascono disattivate.

void setup() {
  //test lcd
  lcdTask = new LcdTask();
  lcdTask->setPrint("Ciao bro");
  lcdTask->tick();
  
  Serial.begin(9600);
  ledA = new LedImpl(13, OUTPUT);
  ledATask = new LedTask(ledA);
  ledATask-> init(1000);
  ledB = new LedImpl(12, OUTPUT);
  ledBTask = new LedTask(ledB);
  ledBTask-> init(1000);
  ledC = new LedImpl(11, OUTPUT);
  ledCTask = new LedTask(ledC);
  ledCTask-> init(2000);


  sched = new Scheduler();
  sched->init(1000);
  
  ledA->turnOn();

  //sched->addTask(ledATask);
  sched->addTask(ledBTask);
  sched->addTask(ledCTask);

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
    sched->deactivateAllTasks();
    st->setActive(true);
    ledB->turnOn();
    ledC->turnOff();
  } 
  //pre alarm
  else if (distance < PE_ALARM)
  {
    sched->deactivateAllTasks();
    st->setActive(true);
    ledCTask->setActive(true);
  } 
  //alarm
  else
  {
    ledB->turnOff();
    ledC->turnOn();
  }
  
 
}

