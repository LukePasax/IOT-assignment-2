#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "Button.h"
#include "ComponentImpl.h"

class ButtonImpl: public Button {
 
public: 
  using Button::Button;
  bool isPressed();
  bool isClicked();
  void sync();

private:
  bool pressed = false;
  bool clicked = false; 
};

#endif