#include <Arduino.h>
#include "ButtonTask.h"

ButtonTask::ButtonTask(ButtonImpl *b) {
  this->b = b;
}

void ButtonTask::init(int period) {
  Task::init(period);
}

void ButtonTask::tick() {
  if (digitalRead(b->getPin()) == HIGH) {
    if (b->isPressed() == false) {
        b->setPressed(true);
        Serial.println("Button pressed");
    } else {
        b->setPressed(false);
        Serial.println("Button released");
    }
   }
}
