
#ifndef __POT__
#define __POT__

#include "Component.h"
class Potentiometer : public Component{
 
public: 
  using Component::Component;
  int getValue();
};

#endif