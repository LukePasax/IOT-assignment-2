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
#include "LightSystemTask.h"
#include "SituationTask.h"
#include "ButtonTask.h"

#define schedulePeriod 500

Led *ledA;
Led *ledB;
Led *ledC;
ButtonImpl *button;
Scheduler sched;
LedTask* ledCTask;
LcdTask* lcdTask;
Sonar* s;
SonarTask* st;
SituationTask* situationTask;
MotorImpl* motor;

//tutte le task nascono disattivate.



void setup() {
  //test lcd
  Serial.begin(9600);
  sched.init(schedulePeriod);
  Serial.println("Hello world!");

  Sonar* s = new Sonar(8, 9);
  button = new ButtonImpl(6, INPUT);
  ledA = new LedImpl(4, OUTPUT);
  ledB = new LedImpl(2, OUTPUT);
  ledC = new LedImpl(3, OUTPUT);
  MotorImpl* motor = new MotorImpl(11);
  PirImpl* pir = new PirImpl(4, INPUT);
  LightSensorImpl* lsensor = new LightSensorImpl(5, INPUT);
  PotentiometerImpl* pot = new PotentiometerImpl(A0);

  ledCTask = new LedTask(ledC);
  ledCTask->init(2000);
  sched.addTask(ledCTask);

  lcdTask = new LcdTask();
  lcdTask->init(schedulePeriod);
  sched.addTask(lcdTask);

  LightSystemTask* ls = new LightSystemTask(ledA, pir, lsensor);
  ls->init(3000);
  sched.addTask(ls);


  situationTask = new SituationTask(s, ledCTask, ledB, motor, lcdTask, pot, button);
  situationTask->init(3000);
  sched.addTask(situationTask);
  situationTask->setActive(true);
  
  ButtonTask* bt = new ButtonTask(button);
  bt->init(schedulePeriod);
  bt->setActive(true);
  sched.addTask(bt);


}

void loop() {
  sched.schedule();
}