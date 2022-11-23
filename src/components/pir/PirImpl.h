#ifndef __PIRIMPL__
#define __PIRIMPL__

#include "../ComponentImpl.h"

class PirImpl : public ComponentImpl{
    public:
        using ComponentImpl::ComponentImpl;
        virtual void detectMove() = 0;
        virtual bool isMotionDetected() = 0;
    private: 
        bool motionDetected;

};

#endif