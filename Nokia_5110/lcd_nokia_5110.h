/* -------------------------------------------------------------------------
@file Nokia_5110.h

@date 03/30/18 20:08:27
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
#ifndef NOKIA_5110_H
#define NOKIA_5110_H

#include <Arduino.h>

/* NOTE(elsuizo:2018-03-30):esta mierda es importante para poder compilar como C */

#ifdef __cplusplus
extern "C" {
#endif

/* NOTE(elsuizo:2018-03-30): Notas de la hoja de datos:
 - El formatod de instrucciones se dividen en dos modos:
   - Si D/C (modo select) es LOW el byte actual es interpretado como un byte de comando, ver la tabla 1
   - Si D/C es seteado HIGH los siguientes bytes son guardados en la memoria RAM del display. Despues de
   Cada byte de dato el contador de direccion(???) se incrementa automaticamente. El nivel del D/C se lee
   durante el ultimo bit del byte de datos
 - La comunicacion serial comienza cuando SCE esta en HIGH, en este estado los pulsos de SCLK no tienen influencia
   y no se consume energia por la comunicacion serial, un flanco negativo sobre SCE habilita la interface serial e
   indica el comienzo de transmision de datos.
 - Cuando SCE esta HIGH, las seniales de SCLK son ignoradas; durante el tiempo que esta HIGH SCE la interface serie
   es inicializada(o sea que para inicializar la comunicacion hay que poner SCE en HIGH)
 - SDIN es sampleado en los flancos positivos de SCLK
 - D/C indica cuando el byte es un comando(D/C=LOW) o datos para la RAM(D/C=HIGH) y es leido con el octavo pulso de SCLK
 - Si SCE permanece LOW despues de el ultimo bit de comando/datos byte, la interface serie espera el bit 7 de el proximo
   byte como el nuevo flanco positivo de SCLK
 - Un pulso con RES interrumpe la transmision. No se escribe ningun dato en la RAM, los registros se limpian. SI SCE es LOW
   despues de un flanco positivo de RES, la comunicacion serie esta lista para recibir el bit 7 de comando/datos byte
 - INICIALIZACION: Una vez que se le da energia al lcd los contenidos de todos los registros y memoria RAM son indefinidos, por
   ello debemos inicializar con un pulse en RES(recordar que es LOW) y en un tiempo especificado(con un maximo de 100 ms)
*/

/*-------------------------------------------------------------------------
                     datatypes
-------------------------------------------------------------------------*/
/**
 * @brief: Pins for the lcd Nokia 5110
 */
enum LCD_PIN {
   LCD_PIN_RES  = 6, /* external reset input: warning is active in low mode */
   LCD_PIN_SCE  = 7, /* chip enable: warning is active in low mode */
   LCD_PIN_DC   = 5, /* data/clock mode select */
   LCD_PIN_SDIN = 4, /* serial data input */
   LCD_PIN_SCLK = 8, /* serial clock input */
};

enum INTRUCTIONS {
   FUNCTION_SET            = bit(5), /* set the bit 5 to begins table 1 */
   EXTENDED_FUNCTION_SET   = FUNCTION_SET | bit(0), /* for set the extendend set of instructions */
   BASIC_FUNCTION_SET      = FUNCTION_SET, /* set H to low */
   DISPLAY_CONTROL_SET     = bit(3),
   SET_Y                   = bit(6),
   SET_X                   = bit(7),
   NORMAL_MODE_SET         = DISPLAY_CONTROL_SET | bit(2),
   BIAS_SYSTEM_ENABLED_SET = bit(4), /* set the bias of voltages bit ready for initialization */
   MUX_48_SET              = BIAS_SYSTEM_ENABLED_SET | bit(1) | bit(0),
   V_OP_SET                = bit(7), /* set bits values for initialize the contrast */
};



void lcd_init(void);

void send_character(char c);

void lcd_clear(void);

void lcd_write(const char* message);

#ifdef __cplusplus
}
#endif

#endif
