/* -------------------------------------------------------------------------
@file servo-test.ino

@date 07/10/20 17:22:41
@author Martin Noblia
@email mnoblia@disroot.org

@brief
Hola mundo con un servo
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

/* conexiones para no olvidar:
red   ---> vcc=5v
black ---> gnd
white ---> signal
*/

#include<Servo.h>

#define SERVO_PIN 9

Servo servo;

void setup() {
   Serial.begin(9600);

   servo.attach(SERVO_PIN);
}

void loop() {

   servo.write(0);
   delay(1000);

   servo.write(90);
   delay(1000);

   servo.write(180);
   delay(1000);
}

