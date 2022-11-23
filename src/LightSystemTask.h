#include <Arduino.h>
#include "Task.h"
#include "components/led/Led.h"
#include "components/pir/PirImpl.h"
#include "components/lightsensor/LightSensor.h"
class LightSystemTask : public Task {
    public:
        LightSystemTask(Led *led, PirImpl *pir, LightSensor *lightSensor);
        void init(int period);
        void tick();
        void getTaskName();


    private:
        bool state;
        Led *led;
        PirImpl *pir;
        LightSensor *lightSensor;
};
