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


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led = new LedImpl(13, OUTPUT);
  button = new ButtonImpl(7, INPUT, false);
  t = new MyTask(led);
  Serial.println(button->getPin());
  sched = new Scheduler();
  sched->init(1000);
  sched->addTask(t);
}

void loop() {
  // put your main code here, to run repeatedly:
  sched->schedule();
}