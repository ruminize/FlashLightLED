/*
  Flight.h - Library for flashing NEC IR controlled led light reels.
  Created by Jake E. Danforth, January 17, 2020.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Flight.h"
#include <IRremote.h>
IRsend irsend;
const byte ROWS = 4;
const byte COLS = 5;
//const long unsigned int dim = 0xFF3AC5;
// const long unsigned int colors [] = {0xFF1AE5, 0xFF9A65, 0xFFA25D};
const long unsigned int colors [ROWS][COLS] = {
  {0xFF1AE5, 0xFF2AD5, 0xFF0AF5, 0xFF38C7, 0xFF18E7},
  {0xFF9A65, 0xFFAA55, 0xFF8A75, 0xFFB847, 0xFF9867},
  {0xFFA25D, 0xFF926D, 0xFFB24D, 0xFF7887, 0xFF58A7},
  {0xFF22DD, 0xFF12ED, 0xFF32CD, 0xFFF807, 0xFFD827}
};
// const char* colorstwo [] = {"red", "green", "blue"};
// long unsigned int c = colors[random(0,3)];
String colorCol = "rgbw";

Flight::Flight(int pin){
  _pin = pin;
}

void Flight::dim(){
  for (int i = 0; i < 7; i++) {
    irsend.sendNEC(0xFFBA45, 32);
    delay(100);
  }
}

void Flight::brighten(){
  for (int i = 0; i < 7; i++) {
    irsend.sendNEC(0xFF3AC5, 32);
    delay(100);
  }
}

void Flight::on(){
  irsend.sendNEC(0xFF02FD, 32);
}

void Flight::jump3(){
  irsend.sendNEC(0xFF20DF, 32);
}

void Flight::jump7(){
  irsend.sendNEC(0xFFA05F, 32);
}

void Flight::fade3(){
  irsend.sendNEC(0xFF609F, 32);
}

void Flight::fade7(){
  irsend.sendNEC(0xFFE01F, 32);
}

void Flight::flash(){
  irsend.sendNEC(0xFFD02F, 32);
}

void Flight::auto1(){
  irsend.sendNEC(0xFFF00F, 32);
}

void Flight::play(){
  irsend.sendNEC(0xFF827D, 32);
}

void Flight::togglePower(){
  irsend.sendNEC(0xFF02FD, 32);
}

void Flight::quick(int count){
  // irsend.sendNEC(0xFFE817, 32);
  for (int i = 0; i < count; i++) {
    irsend.sendNEC(0xFFE817, 32);
    delay(100);
  }
}

void Flight::slow(int count){
  for (int i = 0; i < count; i++) {
    irsend.sendNEC(0xFFC837, 32);
    delay(100);
  }
}

void Flight::color(int col, int row, int lumen){
  irsend.sendNEC(colors[col][row], 32);
  if(lumen > 0){
    setLumens(lumen);
  }
}

void Flight::randomColors(const char* colorColumn){
  int column = colorCol.indexOf(colorColumn[0]);
  Serial.println(colorColumn[0]);
  if(column > -1){
    irsend.sendNEC(colors[column][random(0,COLS)], 32);
  }else{
    const long unsigned int* rows = colors[random(0,ROWS)];
    irsend.sendNEC(rows[random(0,COLS)], 32);
  }
}

void Flight::setLumens(int level){
  dim();
  for (int i = 0; i < level; i++) {
    irsend.sendNEC(0xFF3AC5, 32);
    delay(100);
  } 
}

void setSpeed(int level){
  
}