/* -------------------------------------------------------------------------
@file nrf24l01-test-remote.ino

@date 07/18/20 13:28:50
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
#include <SPI.h>
#include <RH_NRF24.h>

RH_NRF24 nrf24;

void setup() {

   pinMode(13, OUTPUT);
   Serial.begin(9600); // inicializa monitor serie a 9600 bps
   if (!nrf24.init()) // si falla inicializacion de modulo muestra texto
      Serial.println("fallo de inicializacion");
   if (!nrf24.setChannel(2)) // si falla establecer canal muestra texto
      Serial.println("fallo en establecer canal");
   if (!nrf24.setRF(RH_NRF24::DataRate250kbps, RH_NRF24::TransmitPower0dBm)) // si falla opciones
      Serial.println("fallo en opciones RF"); // RF muestra texto
}

void loop()
{
   int pin_value = 0;
   Serial.println("Enviando mensaje a la base"); // muestra texto
   uint8_t data[] = "Hola desde lejos!"; // almacena texto a enviar
   nrf24.send(data, sizeof(data)); // envia el texto

   nrf24.waitPacketSent(); // espera hasta realizado el envio

   uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN]; // buffer con longitud maxima de 32 bytes
   uint8_t len = sizeof(buf); // obtiene longitud de la cadena

   if (nrf24.available()) // si hay informacion disponible
   {
      if (nrf24.recv(buf, &len)) // si hay informacion valida en el buffer
      {
         Serial.print("Recibido: "); // muestra texto
         Serial.println((char*)buf); // muestra contenido del buffer
         pin_value = digitalRead(13);
         if (pin_value) {
            digitalWrite(13, LOW);
         } else {
            digitalWrite(13, HIGH);
         }
      }
      else
      {
         Serial.println("fallo en recepcion"); // muestra texto
      }
   }
   delay(3000); // demora de 1 segundo entre envios
}


