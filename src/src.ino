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
  ledCTask->init(PE_LEDCTASK);
  sched.addTask(ledCTask);

  lcdTask = new LcdTask();
  lcdTask->init(PE_LCDTASK);
  sched.addTask(lcdTask);

  LightSystemTask* ls = new LightSystemTask(ledA, pir, lsensor);
  ls->init(PE_LIGHTSYSTEMTASK);
  sched.addTask(ls);


  situationTask = new SituationTask(s, ledCTask, ledB, motor, lcdTask, pot, button);
  situationTask->init(PE_SITUATIONTASK);
  sched.addTask(situationTask);
  situationTask->setActive(true);
  situationTask->addListener((Listener*)ledCTask);
  situationTask->addListener((Listener*)ls);
  
  ButtonTask* bt = new ButtonTask(button);
  bt->init(PE_BUTTONTASK);
  bt->setActive(true);
  sched.addTask(bt);


}

void loop() {
  sched.schedule();
}