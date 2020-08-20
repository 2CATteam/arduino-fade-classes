#include "fadeClasses.h"

//This is such bad form please never ever ever do this like this... But I repeat it so many times and it's hard to edit all of them.
//Play around with these args.
//The first is the fadeAmount (how fast it goes through its cycles
//The second is the minimum number before the pin "bounces" back to going to the top
//The third is the max before the pin "bounces" back down
#define args 4, -64, 256

//All of our pin objects. For any more, I'd throw them in an array and iterate, but... Eh... It's fine for now.
Fade* white;
Fade* red;
Fade* blue;
Fade* green;
Fade* yellow;

void setup() {
  //Pin 3, no waiting
  white = new Fade(3, args);
  //Pin 5, 32 waiting cycles
  red = new Fade(5, args, 32);
  //etc
  blue = new Fade(6, args, 64);
  green = new Fade(9, args, 96);
  yellow = new Fade(10, args, 128);
}

//Just call each object's step function
void loop() {
  white->stepBright();
  red->stepBright();
  blue->stepBright();
  green->stepBright();
  yellow->stepBright();
  delay(30);
}
//If you want to turn them all off, just analogWrite() each pin and don't call the step functions.
//When you want to restart the pattern, just call each object's reset() function
