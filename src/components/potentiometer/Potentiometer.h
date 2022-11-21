
#ifndef __POT__
#define __POT__

#include "../ComponentImpl.h"
class Potentiometer : public Component{
 
public: 
  using Component::Component;
  int getValue();
};

#endif