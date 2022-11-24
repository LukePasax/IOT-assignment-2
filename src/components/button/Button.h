#ifndef __BUTTON__
#define __BUTTON__
#include "../ComponentImpl.h"

class Button : public ComponentImpl {
 
public:
  using ComponentImpl::ComponentImpl;
  virtual bool isPressed() = 0;
  virtual void setPressed(bool pressed) = 0;

private:
  bool pressed;

};

#endif