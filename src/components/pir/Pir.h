#ifndef __PIR__
#define __PIR__

#include "Component.h"
class Pir:  public Component{
 
public:     
  void sync();
  bool isDetected();
  void calibrate();
  long getLastSyncTime();

protected: 
  void updateSyncTime(long time);

private:
  long lastTimeSync;
  bool detected;
};

#endif