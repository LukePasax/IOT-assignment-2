
#ifndef __POT__
#define __POT__

#include "Component.h"
class Potentiometer : public Component{
 
public: 
  using Component::Component;
  float getValue();
  virtual void sync();
  long getLastSyncTime();

protected: 
  void updateSyncTime(long time);
  
private:
  long lastTimeSync;
  float value;
};

#endif