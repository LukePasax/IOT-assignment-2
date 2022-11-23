#include <Arduino.h>
#include "Task.h"
#include "components/sonar/Sonar.h"
#include "LedTask.h"
#include "components/motor/Motor.h"
#include "LightSystemTask.h"
#include "LcdTask.h"
#include "components/potentiometer/PotentiometerImpl.h"

class SituationTask : public Task {
    public:
        SituationTask(Sonar *s, LedTask *ledCTask, Led *LedB, Led *LedC, Motor* motor, LightSystemTask* ls, LcdTask* lcdTask, PotentiometerImpl* pot);
        void init(int period);
        void tick();
        void getTaskName();

    private:
        int getSituation(float distance);
        Sonar *s;
        Led *ledB;
        Led *ledC;
        LedTask *ledCTask;
        Motor *m;
        LightSystemTask *ls;
        LcdTask *lcdTask;
        PotentiometerImpl *pot;
        
};
