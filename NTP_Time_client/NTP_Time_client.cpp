/* -------------------------------------------------------------------------
@file NTP_Time_client.cpp

@date
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Example for getting accurate time from NTP server
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
#include "NTP_Time_client.h"

/*-------------------------------------------------------------------------
                        methods implementations
-------------------------------------------------------------------------*/

/**
 * @brief NTPTimeClient constructor
 *
 * @param utc_timezone(float): UTC valid timezone
 * @param ip(IPAddress): ip address of NTP server
 */
NTPTimeClient::NTPTimeClient(float utc_timezone, IPAddress ip) {
  this->utc_timezone = utc_timezone;
  this->time_server_ip = ip;
}

/**
 * @brief Update the actual time from NTP time server
 */
void NTPTimeClient::update_time() {
  udp.begin(local_port);

  sendNTPpacket(time_server_ip); // send an NTP packet to a time server
  // wait to see if a reply is available
  delay(1000);
  int cb = udp.parsePacket();
  if (!cb) {
    Serial.println("no packet yet");
  }
  else {
    Serial.print("packet received, length=");
    Serial.println(cb);
    // We've received a packet, read the data from it
    udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

    //the timestamp starts at byte 40 of the received packet and is four bytes,
    // or two words, long. First, esxtract the two words:

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    // combine the four bytes (two words) into a long integer
    // this is NTP time (seconds since Jan 1 1900):
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    Serial.print("Seconds since Jan 1 1900 = " );
    Serial.println(secsSince1900);

    // now convert NTP time into everyday time:
    Serial.print("Unix time = ");
    // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
    const unsigned long seventyYears = 2208988800UL;
    // subtract seventy years:
    this->epoch = secsSince1900 - seventyYears;
    // print Unix time:
    Serial.println(this->epoch);
    this->localMillisAtUpdate = millis();
    //set time
    setTime(get_current_time_without_offset());
  }
}


// send an NTP request to the time server at the given address
unsigned long NTPTimeClient::sendNTPpacket(IPAddress& address)
{
  Serial.println("sending NTP packet...");
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  udp.beginPacket(address, 123); //NTP requests are to port 123
  udp.write(packetBuffer, NTP_PACKET_SIZE);
  udp.endPacket();
}

String NTPTimeClient::get_year(){
  return String(year());
}

String NTPTimeClient::get_month(){
  int nMonth = month();
  if(nMonth < 10){
    return "0" + String(nMonth);
  }
  return String(nMonth);
}

String NTPTimeClient::get_day(){
  int nDay = day();
  if(nDay < 10){
    return "0" + String(nDay);
  }
  return String(nDay);
}

String NTPTimeClient::getFormattedDate(String seperator) {
  return get_year() + seperator + get_month() + seperator + get_day();
}

String NTPTimeClient::get_hours() {
    if (this->epoch == 0) {
      return "--";
    }
    int hours = hour(); //((getCurrentEpochWithUtcOffset()  % 86400L) / 3600) % 24;
    if (hours < 10) {
      return "0" + String(hours);
    }
    return String(hours); // print the hour (86400 equals secs per day)

}

String NTPTimeClient::get_minutes() {
    if (this->epoch == 0) {
      return "--";
    }
    int minutes = minute(); // ((getCurrentEpochWithUtcOffset() % 3600) / 60);
    if (minutes < 10 ) {
      // In the first 10 minutes of each hour, we'll want a leading '0'
      return "0" + String(minutes);
    }
    return String(minutes);
}

String NTPTimeClient::get_seconds() {
    if (this->epoch == 0) {
      return "--";
    }
    int seconds = second(); //getCurrentEpochWithUtcOffset() % 60;
    if ( seconds < 10 ) {
      // In the first 10 seconds of each minute, we'll want a leading '0'
      return "0" + String(seconds);
    }
    return String(seconds);
}

String NTPTimeClient::getFormattedTime(String seperator) {
  return get_hours() + seperator + get_minutes() + seperator + get_seconds();
}

unsigned long NTPTimeClient::get_current_time() {
  return this->epoch + ((millis() - this->localMillisAtUpdate) / 1000);
}

unsigned long NTPTimeClient::get_current_time_without_offset() {
  return get_current_time() + round(3600 * this->utc_timezone);
}
