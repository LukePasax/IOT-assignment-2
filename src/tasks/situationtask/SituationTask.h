#ifndef __SITUATIONTASK__
#define __SITUATIONTASK__

#include <Arduino.h>
#include "Task.h"
#include "components/sonar/Sonar.h"
#include "tasks/ledtask/LedTask.h"
#include "components/motor/MotorImpl.h"
#include "tasks/lightsystemtask/LightSystemTask.h"
#include "tasks/lcdtask/LcdTask.h"
#include "components/potentiometer/PotentiometerImpl.h"
#include "Listener.h"
#include "components/button/ButtonImpl.h"
#include "Global.h"


class SituationTask : public Task {
    public:
        SituationTask(Sonar *s, LedTask *ledCTask, LedTask *LedB, 
                                MotorImpl* motor, LcdTask* lcdTask,
                                 PotentiometerImpl* pot, ButtonImpl* b);
        void tick();
        void getTaskName();
        void executeNormal();
        void executePrealarm(float distance);
        void executeAlarm(float distance);
        void init(int period);
        void addListener(Listener* listener);
        void notifyListeners(int value);
    private:
        int getSituation(float distance);
        Sonar *s;
        LedTask *ledBTask;
        LedTask *ledCTask;
        MotorImpl *m;
        LcdTask *lcdTask;
        PotentiometerImpl *pot;
        ButtonImpl *b;
        Listener *listeners[MAX_LISTENER];
        int numListeners;
        
};

#endif