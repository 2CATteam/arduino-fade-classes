#include "Arduino.h"
#include "fadeClasses.h"

//Basic constructor with default values
Fade::Fade(int pin, int fade, int bottom = 0, int top = 255, int wait = 0) {
	pinMode(pin, OUTPUT);
	this->pin = pin;
	this->bottom = bottom;
	this->brightness = bottom;
	this->fadeAmount = fade;
	this->top = top;
  this->wait = wait;
  this->initialWait = wait;
}

//Make a step in the brightness stuff
void Fade::stepBright() {
  //Wait if you need to
  if (this->wait > 0) {
    this->wait -= 1;
    return;
  }
  
  //Change brightness
	this->brightness += this->fadeAmount;
 
  //Write proper brightness
	if (this->brightness > 255) {
		analogWrite(this->pin, 255);
	}
	else if (this->brightness < 0) {
		analogWrite(this->pin, 0);
	} else {
		analogWrite(this->pin, this->brightness);
	}

  //Bounce if needed
	if (this->brightness > this->top || this->brightness < this->bottom) {
		this->fadeAmount *= -1;
	}
}

//Jump forward some number of steps in the cycle.
void Fade::jump(int steps) {
  //Run steps times
  for (int i = 0; i < steps; i++) {
    //Change brightness
  	this->brightness += this->fadeAmount;
   
    //Bounce
	  if (this->brightness > this->top || this->brightness < this->bottom) {
		  this->fadeAmount *= -1;
	  }
  }
}

//Re-initialize everything that changes. Use when you need to restart the loop but don't want to do a bunch of memory wasting.
void Fade::reset() {
  this->brightness = this->bottom;
  if (this->fadeAmount < 0) {
    this->fadeAmount *= -1;
  }
  this->wait = this->initialWait;
}
