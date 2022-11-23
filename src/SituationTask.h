#include <Arduino.h>
#include "Task.h"
#include "components/sonar/Sonar.h"
#include "LedTask.h"
#include "components/motor/Motor.h"
#include "LightSystemTask.h"
#include "LcdTask.h"

class SituationTask : public Task {
    public:
        SituationTask(Sonar *s, LedTask *led, Led *led2, Led *led1, Motor* motor, LightSystemTask* ls, LcdTask* lcdTask);
        void init(int period);
        void tick();
        void getTaskName();

    private:
        Sonar *s;
        Led *l;
        Led *r;
        Motor *m;
        LightSensor *ls;
        LcdTask *lcdTask;
        
};
