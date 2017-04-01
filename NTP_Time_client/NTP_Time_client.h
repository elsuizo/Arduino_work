/* -------------------------------------------------------------------------
@file NTP_Time_client.h

@date 03/31/17 19:39:51
@author Martin Noblia
@email martin.noblia@openmailbox.org

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
#ifndef NTPTIMECLIENT_H
#define NTPTIMECLIENT_H
/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
/* mannage the old version of Arduino IDE */
#if (ARDUINO > 100)
   #include "Arduino.h"
#else
   #include "WProgram.h"
#endif

#include <Time.h>  /* time handles */
#include <Ethernet.h> /* Ethernet stuff */
#include <EthernetUdp.h> /* UDP */
#include <SPI.h> /* SPI comunications */

/*-------------------------------------------------------------------------
                           defines constants
-------------------------------------------------------------------------*/
#define NTP_PACKET_SIZE 48  /* buffer size */

/*-------------------------------------------------------------------------
               class for encapsulate a NTP client connection
-------------------------------------------------------------------------*/
class NTPTimeClient {
   private:
      float utc_timezone = 0.0; /* UTF offset */
      unsigned int localMillisAtUpdate;
      unsigned long epoch = 0;
      IPAddress time_server_ip;
      unsigned int local_port = 8888;
      byte packetBuffer[NTP_PACKET_SIZE]; /* buffer to contain packets */
      EthernetUDP udp; /* UDP object */

   public:
      /* constructor */
      NTPTimeClient(float utc_timezone, IPAddress ip);

      void update_time();
      unsigned long sendNTPpacket(IPAddress& address);

      /* mm-dd-yy */
      String get_month();
      String get_day();
      String get_year();
      String getFormattedDate(String seperator = "-");

      String get_hours();
      String get_minutes();
      String get_seconds();
      String getFormattedTime(String seperator = ":");

      unsigned long get_current_time();
      unsigned long get_current_time_without_offset();

}; /* end NTPTimeClient */

#endif
