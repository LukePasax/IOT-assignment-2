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
LedTask* ledCTask;
LcdTask* lcdTask;
Sonar* s;
SituationTask* situationTask;
MotorImpl* motor;

//tutte le task nascono disattivate.



void setup() {
  //test lcd
  Serial.begin(9600);
  sched.init(PE_SCHEDULER);
  Serial.println("Hello world!");

  Sonar* s = new Sonar(8, 9);
  button = new ButtonImpl(6, INPUT);
  ledA = new LedImpl(4, OUTPUT);
  ledB = new LedImpl(2, OUTPUT);
  ledC = new LedImpl(3, OUTPUT);
  MotorImpl* motor = new MotorImpl(11);
  PirImpl* pir = new PirImpl(7, INPUT);
  LightSensorImpl* lsensor = new LightSensorImpl(A2, INPUT);
  PotentiometerImpl* pot = new PotentiometerImpl(A0);
  ledCTask = new LedTask(ledC);
  lcdTask = new LcdTask();
  LightSystemTask* ls = new LightSystemTask(ledA, pir, lsensor);
  situationTask = new SituationTask(s, ledCTask, ledB, motor, lcdTask, pot, button);
  ButtonTask* bt = new ButtonTask(button);

  lcdTask->init(PE_LCDTASK);
  ledCTask->init(PE_LEDCTASK);
  ls->init(1000);
  situationTask->init(PE_SITUATIONTASK);
  bt->init(PE_BUTTONTASK);

  situationTask->setActive(true);
  bt->setActive(true);
  situationTask->addListener((Listener*)ledCTask);
  situationTask->addListener((Listener*)ls);
  

  sched.addTask(ledCTask);
  sched.addTask(lcdTask);
  sched.addTask(ls);
  sched.addTask(situationTask);
  sched.addTask(bt);

}

void loop() {
  sched.schedule();
}