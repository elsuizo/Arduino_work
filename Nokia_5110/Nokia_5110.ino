/* -------------------------------------------------------------------------
@file Nokia_5110.ino

@date 03/29/18 20:38:14
@author Martin Noblia
@email mnoblia@disroot.org

@brief
Libreria para el display Nokia 5110
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

enum LCD_PIN {
   LCD_PIN_RES  = 6, /* external reset input */
   LCD_PIN_SCE  = 7, /* chip enable */
   LCD_PIN_DC   = 5, /* data/clock mode select */
   LCD_PIN_SDIN = 4, /* serial data input */
   LCD_PIN_SCLK = 8, /* serial clock input */
}

void setup()
{

}

void loop()
{
}
