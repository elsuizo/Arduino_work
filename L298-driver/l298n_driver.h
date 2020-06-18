/* -------------------------------------------------------------------------
@file l298n_driver.h

@date 06/18/20 16:18:28
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
#ifndef _L298N_DRIVER_
#define _L298N_DRIVER_

#include<stdio.h>
#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif
/*-------------------------------------------------------------------------
                        pin definition for Arduino
-------------------------------------------------------------------------*/
#define PWMA 3     /** pwm output for motorA */
#define AIN1 1 /** direction output motorA */
#define AIN2 2 /** direction output motorA */

#define PWMB 5     /** pwm output for motorB */
#define BIN1 6 /** direction output motorB */
#define BIN2 7 /** direction output motorB */

/*-------------------------------------------------------------------------
                              custom datatypes
-------------------------------------------------------------------------*/
enum MOTORS {
   MOTOR_A,
   MOTOR_B,
};

enum TURNING_SENSE {
   CLOCKWISE,
   ANTI_CLOCKWISE,
   STOP,
};

/*-------------------------------------------------------------------------
                           prototypes function
-------------------------------------------------------------------------*/
void l298n_driver_init(void);

void
l298n_driver_move(enum MOTORS motor, uint8_t speed, enum TURNING_SENSE direction);

void
l298n_driver_stop(void);

void
l298n_driver_move_clockwise(uint8_t speed);

void
l298n_driver_move_anti_clockwise(uint8_t speed);

void
l298n_driver_rigth(uint8_t speed, uint8_t offset);

void
l298n_driver_left(uint8_t speed, uint8_t offset);

#ifdef __cplusplus
}
#endif

#endif
