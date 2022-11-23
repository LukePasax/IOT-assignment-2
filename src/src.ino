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

//tutte le task nascono disattivate.

MotorImpl* motor;
PotentiometerImpl pot(A0);

void setup() {
  //test lcd

  
  Serial.begin(9600);
  
  lcdTask->setPrint("Ciao bro");
  lcdTask->tick();
  Sonar* s = new Sonar(8, 9);
  lcdTask = new LcdTask();
  ledB = new LedImpl(2, OUTPUT);
  ledC = new LedImpl(3, OUTPUT);
  ledCTask = new LedTask(ledC);
  MotorImpl* motor = new MotorImpl(11);
  PirImpl* pir = new PirImpl(4, INPUT);
  LightSensorImpl* lsensor = new LightSensorImpl(5, INPUT);
  LightSystemTask* ls = new LightSystemTask(ledA, pir, lsensor);
  SituationTask* situationTask = new SituationTask(s, ledCTask, ledB, ledC, motor, ls, lcdTask, pot);
  sched->addTask(ledCTask);
  sched->addTask(lcdTask);

}

void loop() {
 
}