#include <Arduino.h>
#include "Task.h"
#include "LcdTask.h"

/* Wiring: SDA => A4, SCL => A5 */

LcdTask::LcdTask() {
    this->print = "";
    lcd = new LiquidCrystal_I2C(0x27, 20, 4);
    this->lcd->init();
    this->lcd->backlight();
}
void LcdTask::init(int period){
    Task::init(period);
}

void LcdTask::getTaskName() {
    Serial.println("LcdTask");
}
void LcdTask::tick(){
    this->lcd->clear();
    this->lcd->setCursor(2, 1);
    this->lcd->print(this->print);
}
void LcdTask::setPrint(String print){
    this->print = print;
}