#include <Arduino.h>
#include "Task.h"
#include "components/Sonar.h"

class SonarTask : public Task {
    public:
        SonarTask(Sonar *s);
        void init(int period);
        void tick();
        void getTaskName();
        

    private:
        Sonar *s;
};