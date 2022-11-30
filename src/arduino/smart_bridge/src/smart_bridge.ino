//Lorenzo Tosi - lorenzo.tosi10@studio.unibo.it - 0000997569
//Andrea Zavatta - andrea.zavatta3@studio.unibo.it - 0000989124
#include <Arduino.h>
#include <EnableInterrupt.h>
#include "components/led/LedImpl.h"
#include "components/button/ButtonImpl.h"
#include "Scheduler.h"
#include "tasks/ledtask/LedTask.h"
#include "components/sonar/Sonar.h"
#include "tasks/lcdtask/LcdTask.h"
#include <LiquidCrystal_I2C.h>
#include "components/motor/MotorImpl.h"
#include "components/pir/PirImpl.h"
#include "components/potentiometer/PotentiometerImpl.h"
#include "components/lightsensor/LightSensorImpl.h"
#include "tasks/lightsystemtask/LightSystemTask.h"
#include "tasks/situationtask/SituationTask.h"
#include "tasks/buttontask/ButtonTask.h"


Led *ledA;
Led *ledB;
Led *ledC;
ButtonImpl *button;
Scheduler sched;
LedTask* ledATask;
LedTask* ledBTask;
LedTask* ledCTask;
LcdTask* lcdTask;
LightSystemTask* ls;
ButtonTask* bt;
Sonar* s;
SituationTask* situationTask;
MotorImpl* motor;
PirImpl* pir;
LightSensorImpl* lsensor;
PotentiometerImpl* pot;

//tutte le task nascono disattivate.

void setup() {
  Serial.begin(9600);
  sched.init(PE_SCHEDULER);

  s = new Sonar(8, 9);
  button = new ButtonImpl(6, INPUT);
  ledA = new LedImpl(4, OUTPUT);
  ledB = new LedImpl(2, OUTPUT);
  ledC = new LedImpl(3, OUTPUT);
  motor = new MotorImpl(11);
  pir = new PirImpl(7, INPUT);
  lsensor = new LightSensorImpl(A2, INPUT);
  pot = new PotentiometerImpl(A0);
  
  ledATask = new LedTask(ledA);
  ledBTask = new LedTask(ledB);
  ledCTask = new LedTask(ledC);
  lcdTask = new LcdTask();
  ls = new LightSystemTask(ledATask, pir, lsensor);
  situationTask = new SituationTask(s, ledCTask, ledBTask, motor, lcdTask, pot, button);
  bt = new ButtonTask(button);

  ledATask->init(500);
  ledBTask->init(500);
  ledCTask->init(PE_LEDCTASK);
  lcdTask->init(PE_LCDTASK);
  ls->init(1000);
  situationTask->init(PE_SITUATIONTASK);
  bt->init(1000);

  situationTask->setActive(true);
  bt->setActive(true);
  situationTask->addListener((Listener*)ls);
  

  sched.addTask(ledATask);
  sched.addTask(ledBTask);
  sched.addTask(ledCTask);
  sched.addTask(lcdTask);
  sched.addTask(ls);
  sched.addTask(situationTask);
  sched.addTask(bt);

}

void loop() {
  sched.schedule();
}