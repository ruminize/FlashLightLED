/*
  FlashlightLED.h - Library for flashing NEC IR controlled led light reels.
  Created by Jake E. Danforth, January 17, 2020.
  Released into the public domain.
*/

#ifndef FlashlightLED_h
#define FlashlightLED_h

#include "Arduino.h"

class FlashlightLED
{
  public:
    FlashlightLED();
    FlashlightLED& BRIGHTEN(int pulses = 10);
    FlashlightLED& DIM(int pulses = 10);
    FlashlightLED& LUMENS(int pulses = 4);
    FlashlightLED& QUICK(int pulses = 65);
    FlashlightLED& SLOW(int pulses = 65);
    FlashlightLED& SPEED(int pulses = 30);
    FlashlightLED& COLOR(int col, int row);
    FlashlightLED& RANDOM_COLOR(int col = -1);
    FlashlightLED& ARROW(int col, int row);
    FlashlightLED& PLAY();
    FlashlightLED& POWER();
    FlashlightLED& JUMP3();
    FlashlightLED& JUMP7();
    FlashlightLED& FADE3();
    FlashlightLED& FADE7();
    FlashlightLED& FLASH();
    FlashlightLED& AUTO();
    FlashlightLED& DIY1();
    FlashlightLED& DIY2();
    FlashlightLED& DIY3();
    FlashlightLED& DIY4();
    FlashlightLED& DIY5();
    FlashlightLED& DIY6();
    FlashlightLED& DELAY(unsigned long time = 0);
    private:
    void SEND(long int code, int count);
};

#endif