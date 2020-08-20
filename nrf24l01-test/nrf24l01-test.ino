/* -------------------------------------------------------------------------
@file nrf24l01-test.ino

@date 07/18/20 00:34:29
@author Martin Noblia
@email mnoblia@disroot.org

@brief
Test para los famosos modulos rf nrf24l01
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
                           pinout
 CE   ---> 8
 CSN  ---> 10
 SCK  ---> 13
 MOSI ---> 11
 MISO ---> 12
-------------------------------------------------------------------------*/
/* NOTE(elsuizo:2020-07-18): hay que acordarse de que necesitamos que vcc sea
 una fuente estable de tension de 3.3 v */

// Primer programa lado Base

#include <SPI.h>	// incluye libreria SPI para comunicacion con el modulo
#include <RH_NRF24.h>	// incluye la seccion NRF24 de la libreria RadioHead

RH_NRF24 nrf24;

void setup() {

   Serial.begin(9600);
   if (!nrf24.init()) {
      Serial.println("fallo de inicializacion");
   }

   /* cuando seteamos el canal estamos eligiendo un canal de comunicacion al
   cual poner informacion, osea que del otro lado tiene que estar seteado en
   el mismo canal que nosotros aqui */
   if (!nrf24.setChannel(2)) {
      Serial.println("fallo en establecer canal");
   }

   if (!nrf24.setRF(RH_NRF24::DataRate250kbps, RH_NRF24::TransmitPower0dBm)) {
      Serial.println("fallo en opciones RF");
   }

   Serial.println("Base iniciada");  // texto para no comenzar con ventana vacia
}

void loop() {

   if (nrf24.available()) // si hay informacion disponible
   {
      uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];	// buffer con longitud maxima de 32 bytes
      uint8_t len = sizeof(buf); // obtiene longitud de la cadena
      if (nrf24.recv(buf, &len)) // si hay informacion valida en el buffer
      {
         Serial.print("Recibido: "); // muestra texto
         Serial.println((char*)buf); // muestra contenido del buffer

         uint8_t data[] = "Hola amigo remoto"; // se almacena texto a enviar
         nrf24.send(data, sizeof(data)); // envia texto
         nrf24.waitPacketSent(); // espera hasta realizado el envio
         Serial.println("Respondiendo"); // muestra texto

      }

      else {
         Serial.println("fallo en recepcion"); // muestra texto
      }
   }
}

