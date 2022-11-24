#ifndef __LIGHTSYSTEMTASK__
#define __LIGHTSYSTEMTASK__

#include <Arduino.h>
#include "Task.h"
#include "components/led/Led.h"
#include "components/pir/PirImpl.h"
#include "components/lightsensor/LightSensor.h"
#include "Listener.h"
#include "Global.h"
class LightSystemTask : public Task, public Listener {
    public:
        LightSystemTask(Led *led, PirImpl *pir, LightSensor *lightSensor);
        void init(int period);
        void tick();
        void getTaskName();
        void notified(int notify);

    private:
        bool state;
        Led *led;
        PirImpl *pir;
        LightSensor *lightSensor;

};

#endif