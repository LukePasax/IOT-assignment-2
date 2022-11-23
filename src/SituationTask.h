#ifndef __SITUATIONTASK__
#define __SITUATIONTASK__

#include <Arduino.h>
#include "Task.h"
#include "components/sonar/Sonar.h"
#include "LedTask.h"
#include "components/motor/MotorImpl.h"
#include "LightSystemTask.h"
#include "LcdTask.h"
#include "components/potentiometer/PotentiometerImpl.h"

class SituationTask : public Task {
    public:
        SituationTask(Sonar *s, LedTask *ledCTask, Led *LedB, Led *LedC, /*MotorImpl* motor,*/ LcdTask* lcdTask, LightSystemTask* lst, PotentiometerImpl* pot);
        void init(int period);
        void tick();
        void getTaskName();

    private:
        int getSituation(float distance);
        Sonar *s;
        Led *ledB;
        Led *ledC;
        LedTask *ledCTask;
        //MotorImpl *m;
        LightSystemTask *ls;
        LcdTask *lcdTask;
        PotentiometerImpl *pot;
        
};

#endif