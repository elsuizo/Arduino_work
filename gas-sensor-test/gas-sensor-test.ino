/* -------------------------------------------------------------------------
@file gas-sensor-test.ino

@date 06/28/20 12:20:04
@author Martin Noblia
@email mnoblia@disroot.org

@brief
testeando el sensor de gas MQ-2
la linea MQ la podemos resumir:
MQ-2: gases combustibles y humo
MQ-3: vapor de alcohol
MQ-4: gas natural y metano
MQ-5: gas natural
MQ-6: propano
MQ-7: monoxido de carbono
MQ-8: Hidrogeno
MQ-9: monoxido de carbono y gases combustibles
MQ-135: Amoniaco, Benceno, Vapor de alcohol, Humo
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
#define ANALOG_PIN_READ A0

void setup(void) {
   Serial.begin(115200);
   Serial.println("Initialize serial...");
   /* dicen que no requieren inicializacion pero yo lo hago para hacerlo explicito */
   pinMode(ANALOG_PIN_READ, INPUT);

}

void loop(void) {
   int read = analogRead(ANALOG_PIN_READ);
   Serial.println(read);

   delay(500);
}
