/* -------------------------------------------------------------------------
@file Tb6612_test.ino

@date 12/21/17 18:24:56
@author Martin Noblia
@email mnoblia@disroot.org

@brief
Prueba para el driver de motor tb6612 de sparkfun
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
int STBY = 12; //standby
char val;
int speed=150;


//Motor A
int PWMA = 5; //Speed control
int AIN1 = 7; //Direction
int AIN2 = 6; //Direction

//Motor B
int PWMB = 10; //Speed control
int BIN1 = 8; //Direction
int BIN2 = 9; //Direction

void move(int motor, int speed, int direction);
void stop();
void right();
void left();
void forward();
void backguard();

void setup(){
   Serial.begin(9600);
   pinMode(STBY, OUTPUT);
   pinMode(13, OUTPUT);
   pinMode(PWMA, OUTPUT);
   pinMode(AIN1, OUTPUT);
   pinMode(AIN2, OUTPUT);

   pinMode(PWMB, OUTPUT);
   pinMode(BIN1, OUTPUT);
   pinMode(BIN2, OUTPUT);

   pinMode(13, OUTPUT);
}

void loop(){


   if( Serial.available() )
   {

      val = Serial.read();

   }
   switch (val)
   {
      case 's':
         {
            stop();
            digitalWrite(13,HIGH);
            break;
         }

      case 'a':
         {
            forward();
            digitalWrite(13,LOW);
            break;
         }

      case 'r':
         {
            backguard();
            break;
         }

      case 'i':
         {
            left();
            break;
         }

      case 'd':
         {
            right();
            break;
         }

   }
}

void stop(){
   //enable standby
   digitalWrite(STBY, LOW);
}


void backguard()
{
   move(1, speed, 1); //motor 1, full speed, left
   move(2, speed, 1); //motor 2, full speed, left
}

void forward()
{
   move(1, speed, 0); //motor 1, full speed, left
   move(2, speed, 0); //motor 2, full speed, left
   digitalWrite(13, HIGH);
}

void right()
{
   move(1, speed, 0);
   move(2, speed-20, 1);
}

void left()
{
   move(1, speed-20, 1);
   move(2, speed, 0);
}

void move(int motor, int speed, int direction){
   //Move specific motor at speed and direction
   //motor: 0 for B 1 for A
   //speed: 0 is off, and 255 is full speed
   //direction: 0 clockwise, 1 counter-clockwise

   digitalWrite(STBY, HIGH); //disable standby

   boolean inPin1 = LOW;
   boolean inPin2 = HIGH;

   if(direction == 1){
      inPin1 = HIGH;
      inPin2 = LOW;
   }

   if(motor == 1){
      digitalWrite(AIN1, inPin1);
      digitalWrite(AIN2, inPin2);
      analogWrite(PWMA, speed);
   }else{
      digitalWrite(BIN1, inPin1);
      digitalWrite(BIN2, inPin2);
      analogWrite(PWMB, speed);
   }
}
