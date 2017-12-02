/* -------------------------------------------------------------------------
@file Serial_test.ino

@date 12/02/17 11:16:14
@author Martin Noblia
@email mnoblia@disroot.org

@brief
Arduino serial test, para ver si esta andando el puerto serial
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
/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
/* mannage the old version of Arduino IDE */
#if (ARDUINO > 100)
   #include "Arduino.h"
#else
   #include "WProgram.h"
#endif
void setup()
{
   Serial.begin(115200);
   Serial.println("Initialize the fucking port!!!");
   delay(1000);
}

void loop()
{
   Serial.println("Hello!!! in loop!!!");
   delay(1000);
}
