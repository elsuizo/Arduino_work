/* -------------------------------------------------------------------------
@file Encoder_test.ino

@date 04/21/18 13:01:47
@author Martin Noblia
@email mnoblia@disroot.org

@brief
test para el encoder
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

#define LED1 7
#define LED2 6

#define CHANNEL_A 5
#define CHANNEL_B 4

int read_value_channel_A = 0;
int read_value_channel_B = 0;

void setup()
{
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);

   pinMode(CHANNEL_A, INPUT);
   pinMode(CHANNEL_B, INPUT);
}

void loop()
{
   read_value_channel_A = digitalRead(CHANNEL_A);
   read_value_channel_B = digitalRead(CHANNEL_B);
   digitalWrite(LED1, read_value_channel_A);
   digitalWrite(LED2, read_value_channel_B);

}

