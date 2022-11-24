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
#include "Listener.h"
#include "components/button/ButtonImpl.h"
#define MAX_LISTENER 50

class SituationTask : public Task {
    public:
        SituationTask(Sonar *s, LedTask *ledCTask, Led *LedB, 
                                MotorImpl* motor, LcdTask* lcdTask,
                                 PotentiometerImpl* pot, ButtonImpl* b);
        void init(int period);
        void tick();
        void getTaskName();
        void addListener(Listener* listener){
            if(numListeners < MAX_LISTENER){
                listeners[numListeners] = listener;
                numListeners++;
            }
        };
        void notifyListeners(int value){
            for(int i = 0; i < numListeners; i++){
                if(listeners[i] != NULL){
                    listeners[i]->notified(value);
                }
            }
        };
    private:
        int getSituation(float distance);
        Sonar *s;
        Led *ledB;
        LedTask *ledCTask;
        MotorImpl *m;
        LcdTask *lcdTask;
        PotentiometerImpl *pot;
        ButtonImpl *b;
        Listener *listeners[MAX_LISTENER];
        int numListeners;
        
};

#endif