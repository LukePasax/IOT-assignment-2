#ifndef __PIR__
#define __PIR__

#include "PresenceSensor.h"
#include "Component.h"
class Pir: public PresenceSensor, public Component{
 
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