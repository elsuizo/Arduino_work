/* -------------------------------------------------------------------------
@file l298n_driver.c

@date 06/18/20 16:18:03
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
/* includes */
#include "l298n_driver.h"

/**
 * @brief
 * initialize the driver
 * @return
 */
void l298n_driver_init(void) {
   pinMode(AIN1, OUTPUT);
   pinMode(AIN2, OUTPUT);
   pinMode(BIN1, OUTPUT);
   pinMode(BIN2, OUTPUT);

   pinMode(PWMA, OUTPUT);
   pinMode(PWMB, OUTPUT);
}

/**
 * @brief
 *
 * @param motor
 * @param speed
 * @param direction
 */
void
l298n_driver_move(enum MOTORS motor, uint8_t speed, enum TURNING_SENSE direction) {

   uint8_t in_pin1, in_pin2;
   if (direction == CLOCKWISE) {
      in_pin1 = LOW;
      in_pin2 = HIGH;
   } else if (direction == ANTI_CLOCKWISE) {
      in_pin1 = HIGH;
      in_pin2 = LOW;
   }
   if (motor == MOTOR_A) {
      digitalWrite(AIN1, in_pin1);
      digitalWrite(AIN2, in_pin2);
      analogWrite(PWMA, speed);
   } else{
      digitalWrite(BIN1, in_pin1);
      digitalWrite(BIN2, in_pin2);
      analogWrite(PWMB, speed);
   }
}

/**
 * @brief stop the motor
 */
void
l298n_driver_stop(void) {
   digitalWrite(BIN1, LOW);
   digitalWrite(BIN2, LOW);
   digitalWrite(AIN1, LOW);
   digitalWrite(AIN2, LOW);
}

/**
 * @brief move clockwise
 *
 * @param speed
 */
void
l298n_driver_move_clockwise(uint8_t speed) {
   l298n_driver_move(MOTOR_A, speed, CLOCKWISE);
   l298n_driver_move(MOTOR_B, speed, CLOCKWISE);
}

/**
 * @brief move anti-clockwise
 *
 * @param speed
 */
void
l298n_driver_anti_clockwise(uint8_t speed) {
   l298n_driver_move(MOTOR_A, speed, ANTI_CLOCKWISE);
   l298n_driver_move(MOTOR_B, speed, ANTI_CLOCKWISE);
}


/**
 * @brief
 *
 * @param speed
 * @param offset
 */
void
l298n_driver_rigth(uint8_t speed, uint8_t offset) {
   l298n_driver_move(MOTOR_A, speed, CLOCKWISE);
   l298n_driver_move(MOTOR_B, speed - offset, ANTI_CLOCKWISE);
}

/**
 * @brief
 *
 * @param speed
 */
void
l298n_driver_left(uint8_t speed, uint8_t offset) {
   l298n_driver_move(MOTOR_A, speed - offset, ANTI_CLOCKWISE);
   l298n_driver_move(MOTOR_B, speed, CLOCKWISE);
}
