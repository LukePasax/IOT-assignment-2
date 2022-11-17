#ifndef __BUTTON__
#define __BUTTON__

class Button : public ComponentImpl {
 
public:
  using ComponentImpl::ComponentImpl;
  virtual bool isPressed() = 0;
  virtual bool isClicked() = 0;
  virtual void sync();
  long getLastSyncTime();

protected: 
  void updateSyncTime(long time);

private:
  long lastTimeSync;

};

#endif