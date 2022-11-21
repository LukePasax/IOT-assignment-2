#include <Arduino.h>
#include "../src/lib/LiquidCrystal_I2C/LiquidCrystal_I2C.h"
#include "LcdTask.h"

LcdTask::LcdTask(LiquidCrystal_I2C *lcd) {
    print = "";
    this->lcd = lcd;  
}

void LcdTask::init(int period){
    Task::init(period);
}

void LcdTask::tick(){

}
void LcdTask::setPrint(String print){
    this->print = print;
}