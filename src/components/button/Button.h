#ifndef __BUTTON__
#define __BUTTON__
#include "../ComponentImpl.h"

class Button : public ComponentImpl {
 
public:

  Button(uint8_t pin, uint8_t mode) : ComponentImpl(pin, mode) {}

  virtual bool isPressed() = 0;
  virtual void setPressed(bool pressed) = 0;

private:
  bool pressed;

};

#endif