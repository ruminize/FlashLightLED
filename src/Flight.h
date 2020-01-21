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
    Flight();
    void DIM();
    void BRIGHTEN();
    void ON();
    void PLAY();
    void POWER();
    void QUICK(byte speed = 7);
    void SLOW(byte speed = 7);
    void JUMP3();
    void JUMP7();
    void FADE3();
    void FADE7();
    void FLASH();
    void AUTO();
    void color(byte col, byte row, byte lumen = 0);
    void setLumens(byte level = 0);
    void setSpeed(byte speed = 0);
    void randomColor(byte column);
  private:
};

#endif