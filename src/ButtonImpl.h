#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "Button.h"
#include "Component.h"

class ButtonImpl: public Button, public Component {
 
public: 
  using Component::Component;
  bool isPressed();
  bool isClicked();
  void sync();

private:
  bool pressed;
  bool clicked;
};

#endif