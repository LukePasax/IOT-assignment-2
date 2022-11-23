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
Led *ledA;
Led *ledB;
Led *ledC;
Button *button;
Scheduler sched;
LedTask* ledATask;
LedTask* ledBTask;
LedTask* ledCTask;
LcdTask* lcdTask;
Sonar* s;
SonarTask* st;
SituationTask* situationTask;

//tutte le task nascono disattivate.

MotorImpl* motor;

void setup() {
  //test lcd

  
  Serial.begin(9600);
  Serial.println("Hello world!");
  Sonar* s = new Sonar(8, 9);
  lcdTask = new LcdTask();
  lcdTask->init(1000);
  ledB = new LedImpl(2, OUTPUT);
  ledC = new LedImpl(3, OUTPUT);
  ledCTask = new LedTask(ledC);
  ledCTask->init(2000);
  MotorImpl* motor = new MotorImpl(11);
  PirImpl* pir = new PirImpl(4, INPUT);
  LightSensorImpl* lsensor = new LightSensorImpl(5, INPUT);
  LightSystemTask* ls = new LightSystemTask(ledA, pir, lsensor);
  ls->init(3000);
  PotentiometerImpl* pot = new PotentiometerImpl(A0);
  situationTask = new SituationTask(s, ledCTask, ledB, ledC, motor, lcdTask, ls, pot);
  situationTask->init(3000);
  sched.addTask(ledCTask);
  sched.addTask(lcdTask);
  sched.addTask(situationTask);
  situationTask->setActive(true);
  sched.init(1000);

}

void loop() {
  sched.schedule();
}