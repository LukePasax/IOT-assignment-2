#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "Button.h"

class ButtonImpl: public Button {
 
public: 
  ButtonImpl(uint8_t pin, uint8_t mode):Button(pin, mode){
    this->pressed = pressed;
  };
  bool isPressed();
  void setPressed(bool pressed);

private:
  bool pressed;
};

#endif