/* -------------------------------------------------------------------------
@file QEI-tests.ino

@date 07/22/20 14:14:29
@author Martin Noblia
@email mnoblia@disroot.org

@brief

@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
int pulses;
int deg = 0;
int encoderA = 2;
int encoderB = 3;

int pulsesChanged = 0;
void A_CHANGE();
void B_CHANGE();

void setup(){
  Serial.begin(115200);
  Serial.println("hello");
  pinMode(encoderA, INPUT);
  pinMode(encoderB, INPUT);

  attachInterrupt(0, A_CHANGE, CHANGE);
  attachInterrupt(1, B_CHANGE, CHANGE);

}//setup

void loop(){
  if (pulsesChanged != 0) {
    pulsesChanged = 0;
    Serial.println(pulses);
  }
}

void A_CHANGE(){
  if( digitalRead(encoderB) == 0 ) {
    if ( digitalRead(encoderA) == 0 ) {
      // A fell, B is low
      pulses--; // moving reverse
    } else {
      // A rose, B is low
      pulses++; // moving forward
    }
 } else {
    if ( digitalRead(encoderA) == 0 ) {
      // A fell, B is high
      pulses++; // moving forward
    } else {
      // A rose, B is high
      pulses--; // moving reverse
    }
  }
  // Make sure the pulses are between 0 and 359
  if (pulses > 359) {
    pulses = pulses - 360;
  } else if (pulses < 0) {
    pulses = pulses + 360;
  }

  // tell the loop that the pulses have changed
  pulsesChanged = 1;
}

void B_CHANGE(){
  if ( digitalRead(encoderA) == 0 ) {
    if ( digitalRead(encoderB) == 0 ) {
      // B fell, A is low
      pulses++; // moving forward
    } else {
      // B rose, A is low
      pulses--; // moving reverse
    }
 } else {
    if ( digitalRead(encoderB) == 0 ) {
      // B fell, A is high
      pulses--; // moving reverse
    } else {
      // B rose, A is high
      pulses++; // moving forward
    }
  }
  // Make sure the pulses are between 0 and 359
  if (pulses > 359) {
    pulses = pulses - 360;
  } else if (pulses < 0) {
    pulses = pulses + 360;
  }

  // tell the loop that the pulses have changed
  pulsesChanged = 1;
}
