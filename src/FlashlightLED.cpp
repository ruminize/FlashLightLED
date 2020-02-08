/*
  FlashlightLED.h - Library for flashing NEC IR controlled led light reels.
  Created by Jake E. Danforth, January 17, 2020.
  Released into the public domain.
*/

#include "Arduino.h"
#include <IRremote.h>
#include "FlashlightLED.h"

IRsend irsend;

const int COLOR_COLS = 4;
const int COLOR_ROWS = 5;

const int ARROW_COLS = 3;
const int ARROW_ROWS = 2;

long int colors [4][5] = {
  {0xFF1AE5, 0xFF2AD5, 0xFF0AF5, 0xFF38C7, 0xFF18E7},
  {0xFF9A65, 0xFFAA55, 0xFF8A75, 0xFFB847, 0xFF9867},
  {0xFFA25D, 0xFF926D, 0xFFB24D, 0xFF7887, 0xFF58A7},
  {0xFF22DD, 0xFF12ED, 0xFF32CD, 0xFFF807, 0xFFD827}
};

long int arrows [3][2] = {
  {0xFF28D7,0xFF08F7},
  {0xFFA857, 0xFF8877},
  {0xFF6897, 0xFF48B7}
};

FlashlightLED::FlashlightLED(){}

FlashlightLED& FlashlightLED::BRIGHTEN(int pulses){
  SEND(0xFF3AC5, pulses);
}

FlashlightLED& FlashlightLED::DIM(int pulses){
  SEND(0xFFBA45, pulses);
}

FlashlightLED& FlashlightLED::PLAY(){
  irsend.sendNEC(0xFF827D, 32);
}

FlashlightLED& FlashlightLED::POWER(){
  irsend.sendNEC(0xFF02FD, 32);
}

FlashlightLED& FlashlightLED::COLOR(int col, int row){
  if((col >= 0 && col < COLOR_COLS) && (row >= 0 && row < COLOR_ROWS)){
    irsend.sendNEC(colors[col][row], 32);
  }
}

FlashlightLED& FlashlightLED::ARROW(int col, int row){
  if((col >= 0 && col < ARROW_COLS) && (row >= 0 && row < ARROW_ROWS)){
    irsend.sendNEC(arrows[col][row], 32);
  }
}

FlashlightLED& FlashlightLED::DIY1(){
  irsend.sendNEC(0xFF30CF, 32);
};

FlashlightLED& FlashlightLED::DIY2(){
  irsend.sendNEC(0xFFB04F, 32);
};

FlashlightLED& FlashlightLED::DIY3(){
  irsend.sendNEC(0xFF708F, 32);
};

FlashlightLED& FlashlightLED::DIY4(){
  irsend.sendNEC(0xFF10EF, 32);
};

FlashlightLED& FlashlightLED::DIY5(){
  irsend.sendNEC(0xFF906F, 32);
};

FlashlightLED& FlashlightLED::DIY6(){
  irsend.sendNEC(0xFF50AF, 32);
};

FlashlightLED& FlashlightLED::QUICK(int speed){
  SEND(0xFFE817, speed);
}

FlashlightLED& FlashlightLED::SLOW(int speed){
  SEND(0xFFC837, speed);
}

FlashlightLED& FlashlightLED::AUTO(){
  irsend.sendNEC(0xFFF00F, 32);
}

FlashlightLED& FlashlightLED::FLASH(){
  irsend.sendNEC(0xFFD02F, 32);
}

FlashlightLED& FlashlightLED::JUMP3(){
  irsend.sendNEC(0xFF20DF, 32);
}

FlashlightLED& FlashlightLED::JUMP7(){
  irsend.sendNEC(0xFFA05F, 32);
}

FlashlightLED& FlashlightLED::FADE3(){
  irsend.sendNEC(0xFF609F, 32);
}

FlashlightLED& FlashlightLED::FADE7(){
  irsend.sendNEC(0xFFE01F, 32);
}

FlashlightLED& FlashlightLED::RANDOM_COLOR(int column){
  randomSeed(analogRead(0));
  if(column >= 0 && column < COLOR_COLS){
    irsend.sendNEC(colors[column][random(0, COLOR_ROWS)], 32);
  }else{
    long int* columns = colors[random(0, COLOR_COLS)];
    irsend.sendNEC(columns[random(0, COLOR_ROWS)], 32);
  }
}

FlashlightLED& FlashlightLED::DELAY(unsigned long time){
  delay(time);
}

FlashlightLED& FlashlightLED::LUMENS(int pulses){
  DIM().SEND(0xFF3AC5, pulses);
}

FlashlightLED& FlashlightLED::SPEED(int pulses){
  SLOW().SEND(0xFFE817, pulses);
}

void FlashlightLED::SEND(long int code, int pulses){
   for (int i = 0; i < pulses; i++) {
    irsend.sendNEC(code, 32);
    delay(100);
  } 
}