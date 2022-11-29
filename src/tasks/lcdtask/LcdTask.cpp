#include <Arduino.h>
#include "Task.h"
#include "LcdTask.h"

/* Wiring: SDA => A4, SCL => A5 */

LcdTask::LcdTask() {
    lcd = new LiquidCrystal_I2C(0x27, 20, 4);
    this->lcd->init();
    this->lcd->backlight();
}

void LcdTask::init(int period){
    Task::init(period);
}

void LcdTask::tick(){
    this->lcd->clear();
    this->lcd->setCursor(2, 1);
    this->lcd->print(print1);
    this->lcd->setCursor(2, 2);
    this->lcd->print(print2);
    this->lcd->setCursor(2, 3);
    this->lcd->print(print3);
}

void LcdTask::setPrint(String print1, String print2, String print3){
    this->print1 = print1;
    this->print2 = print2;
    this->print3 = print3;
}
