#ifndef __PIRIMPL__
#define __PIRIMPL__

#include "../ComponentImpl.h"

class PirImpl : public ComponentImpl{
    public:
        using ComponentImpl::ComponentImpl;
        bool isMotionDetected();

};

#endif