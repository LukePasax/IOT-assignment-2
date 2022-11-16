#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "Button.h"
#include "ComponentImpl.h"

class ButtonImpl: public Button, public ComponentImpl {
 
public: 
  bool isPressed();
  bool isClicked();
  void sync();

private:
  bool pressed;
  bool clicked;
};

#endif