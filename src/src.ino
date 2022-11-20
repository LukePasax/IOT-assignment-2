#include <Arduino.h>
#include <EnableInterrupt.h>
#include "components/LedImpl.h"
#include "components/ButtonImpl.h"
#include "Scheduler.h"
#include "LedTask.h"
#include "components/Sonar.h"
#include "SonarTask.h"

Led *led;
Button *button;
Scheduler *sched;
LedTask* ledTask;
Sonar* s;
SonarTask* st;

float distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led = new LedImpl(13, OUTPUT);
  ledTask = new LedTask(led);
  //button = new ButtonImpl(7, INPUT, false);

  
  ledTask-> init(1000);
  
  sched = new Scheduler();
  sched->init(1000);
  
  led->turnOn();

  sched->addTask(ledTask);
  ledTask->setActive(false);

  s = new Sonar(8, 9);
  st = new SonarTask(s);
  st->init(3000);
  sched->addTask(st);


}

void loop() {
  // put your main code here, to run repeatedly:
  sched->schedule();
  distance = s->getDistance();

  //normal
  if (distance < 0.5)
  {
    ledTask->setActive(true);
  } 
  //pre alarm
  else if (distance < 1.0)
  {

  } 
  //alarm
  else
  {

  }
  
 
}

