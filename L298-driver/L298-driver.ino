/* -------------------------------------------------------------------------
@file L298-driver.ino

@date 06/18/20 16:14:42
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
/* mannage the old version of Arduino IDE */
#if (ARDUINO > 100)
   #include "Arduino.h"
#else
   #include "WProgram.h"
#endif

#include "l298n_driver.h"

void setup() {
   l298n_driver_init();
}

void loop() {
   for (int index = 10; index < 255; index++) {
      l298n_driver_move(MOTOR_A, index, ANTI_CLOCKWISE);
      delay(100);
   }
}

