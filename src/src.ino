#include <Arduino.h>
#include <EnableInterrupt.h>
#include "components/led/LedImpl.h"
#include "components/button/ButtonImpl.h"
#include "Scheduler.h"
#include "LedTask.h"
#include "components/sonar/Sonar.h"
#include "SonarTask.h"
#include "LcdTask.h"
#include <LiquidCrystal_I2C.h>
#include "components/motor/MotorImpl.h"
#include "components/pir/PirImpl.h"
#include "components/potentiometer/PotentiometerImpl.h"
#include "components/lightsensor/LightSensorImpl.h"
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

LightSensor* ls;

//tutte le task nascono disattivate.

MotorImpl* motor;
PotentiometerImpl pot(A0);

void setup() {
  //test lcd

  
  Serial.begin(9600);
  /*lcdTask = new LcdTask();
  lcdTask->setPrint("Ciao bro");
  lcdTask->tick();
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

  sched->addTask(ledATask);
  sched->addTask(ledBTask);
  sched->addTask(ledCTask);

  s = new Sonar(8, 7);
  st = new SonarTask(s);
  st->init(3000);
  st->setActive(true);
  sched->addTask(st);*/

  //servo.attach(9);
  motor = new MotorImpl(9);
  ls = new LightSensorImpl(A1, INPUT);
}

void loop() {
/*
  int val = analogRead(A0);           
  val = map(val, 0, 1023, 0, 180);    
  servo.write(val);                 
  delay(15);
  */

  //motor->potMove(pot.getValue());
  Serial.println(ls->getLight());
  // put your main code here, to run repeatedly:
  /*  sched->schedule();
  distance = s->getDistance();

  
  if (distance < PE_PREALARM)
  {
    sched->deactivateAllTasks();
    st->setActive(true);
    ledB->turnOn();
    ledC->turnOff();
  } 

  else if (distance < PE_ALARM)
  {
    sched->deactivateAllTasks();
    st->setActive(true);
    ledCTask->setActive(true);
  } 
  else
  {
    ledB->turnOff();
    ledC->turnOn();
  }
  */
 
}

