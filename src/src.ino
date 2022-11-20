#include <Arduino.h>
#include <EnableInterrupt.h>
#include "components/LedImpl.h"
#include "components/ButtonImpl.h"
#include "Scheduler.h"
#include "MyTask.h"
#include "components/Sonar.h"
#include "SonarTask.h"

Led *led;
Button *button;
Scheduler *sched;
MyTask* t;
Sonar* s;
SonarTask* st;

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



  s = new Sonar(8, 9);
  st = new SonarTask(s);
  st->init(3000);
  sched->addTask(st);


}

void loop() {
  // put your main code here, to run repeatedly:
  sched->schedule();
}