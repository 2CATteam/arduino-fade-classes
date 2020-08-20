//Public domain or whatever I don't care
#ifndef Fade_h
#define Fade_h

#include "Arduino.h"

class Fade {
  public:
    Fade(int pin, int fade, int bottom = 0, int top = 255, int wait = 0); //Constructor
    void stepBright(); //Each time this is called is a step in the fade process
    void jump(int steps); //
    void reset();
  private:
    int pin;
    int brightness;
    int fadeAmount;
    int top;
    int bottom;
    int wait;
    int initialWait;
};
#endif
