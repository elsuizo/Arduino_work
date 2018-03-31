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
#include "lcd_nokia_5110.h"

/* TODO(elsuizo:2018-03-30):
   - [ ] Limpiar la libreria con los nombre y comentarios
   - [ ] Ver de agregar mas comandos
   - [ ] Ver como hacer animaciones
 */

void setup()
{
   pinMode(LCD_PIN_RES, OUTPUT);
   pinMode(LCD_PIN_SCE, OUTPUT);
   pinMode(LCD_PIN_DC, OUTPUT);
   pinMode(LCD_PIN_SDIN, OUTPUT);
   pinMode(LCD_PIN_SCLK, OUTPUT);
   lcd_init();
   lcd_clear();

}

void loop()
{
   lcd_write("Hello world");
}
