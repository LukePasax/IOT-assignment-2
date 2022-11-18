#include <Arduino.h>
#include <EnableInterrupt.h>
#include "components/LedImpl.h"
#include "components/ButtonImpl.h"
#include "Scheduler.h"
#include "MyTask.h"

Led *led;
Button *button;
Scheduler *sched;
MyTask* t;

long tt;
long t1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led = new LedImpl(13, OUTPUT);
  button = new ButtonImpl(7, INPUT, false);
  t = new MyTask(led);
  t-> init(1000);
  Serial.println(button->getPin());
  sched = new Scheduler();
  sched->init(1000);
  sched->addTask(t);
  t1 = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  sched->schedule();
  tt=millis();
  if (tt-t1>5000) {
    t->setActive(false);
  }
  if(tt-t1>10000) {
    t->setActive(true);
  }
  
}