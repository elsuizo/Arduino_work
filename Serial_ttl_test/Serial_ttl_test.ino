/* -------------------------------------------------------------------------
@file Serial_ttl_test.ino

@date 01/10/18 17:34:36
@author Martin Noblia
@email mnoblia@disroot.org

@brief
Prueba del modulo de conversion ttl to usb
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
/* NOTE(elsuizo:2018-01-10):
En realidad lo que verifique es que no hace falta nada
para hacer que transmita por los pines 0--->rx y 1--->tx
lo que hay que acordarse es que van cruzados, osea que el rx del ttl
va al tx del arduino y el tx del ttl va al rx del arduino
y el mismo programa que funciona con el puerto serie de la conexion usb
funciona con el ttl sin hacer nada(yo pensaba que se tenian que inicializar
los pines o algo asi)
*/

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
   Serial.begin(9600);
   Serial.println("Initialize the fucking port!!!");
   delay(1000);
}

void loop()
{
   Serial.println("Hello!!! in loop!!!");
   delay(1000);
}
