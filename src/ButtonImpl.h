#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "Button.h"
#include "ComponentImpl.h"

class ButtonImpl: public Button {
 
public: 
  using Button::Button;
  bool isPressed();
  //void sync();

private:
  bool pressed = false;
};

#endif