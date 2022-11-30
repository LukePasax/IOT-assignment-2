#ifndef __LIGHTSYSTEMTASK__
#define __LIGHTSYSTEMTASK__

#include <Arduino.h>
#include "Task.h"
#include "tasks/ledtask/LedTask.h"
#include "components/led/Led.h"
#include "components/pir/PirImpl.h"
#include "components/lightsensor/LightSensor.h"
#include "Listener.h"
#include "Global.h"
#include "strategy/StrategyOn.h"
#include "strategy/StrategyOff.h"
class LightSystemTask : public Task, public Listener {
    public:
        LightSystemTask(LedTask *led, PirImpl *pir, LightSensor *lightSensor);
        void init(int period);
        void tick();
        void notified(int notify);

    private:
        bool lightTurnedOn;
        LedTask *led;
        PirImpl *pir;
        LightSensor *lightSensor;
        int notification;
        int time;
};

#endif