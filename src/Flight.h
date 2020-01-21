/*
  Flight.h - Library for flashing NEC IR controlled led light reels.
  Created by Jake E. Danforth, January 17, 2020.
  Released into the public domain.
*/

#ifndef Flight_h
#define Flight_h

#include "Arduino.h"

class Flight
{
  public:
    Flight(int pin);
    void dim();
    void brighten();
    void on();
    void play();
    void togglePower();
    void quick(int count = 7);
    void slow(int count = 7);
    void jump3();
    void jump7();
    void fade3();
    void fade7();
    void flash();
    void color(int col, int row, int lumen = 0);
    void auto1();
    void setLumens(int level);
    void randomColors(const char* colorColumn="z");
  private:
    int _pin;
};

#endif