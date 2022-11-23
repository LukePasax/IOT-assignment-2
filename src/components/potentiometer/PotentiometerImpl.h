#ifndef _POTENTIOMETERIMPL_
#define _POTENTIOMETERIMPL_


class PotentiometerImpl {
 
  public: 
    PotentiometerImpl(uint8_t pin);
    uint8_t getPin();
    int getValue();
  private :
    uint8_t pin;
};

#endif