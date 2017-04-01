#include "NTP_Time_client.h"
/*-------------------------------------------------------------------------
                        global variables
-------------------------------------------------------------------------*/
/* Buenos Aires UTF offset */
const float UTC_OFFSET = -3.0;

/* mac addres of the board */
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xFE, 0x40 };

/* IPAddress for the NTP time server */
IPAddress timeServer(193,92,150,3);
/* create a NTPTimeClient object */
NTPTimeClient timeClient(UTC_OFFSET, timeServer);

void updateData(); /* prototype */
/*-------------------------------------------------------------------------
                              setup
-------------------------------------------------------------------------*/
void setup() {
   Serial.begin(115200);
   Serial.println("Initialize serial...");
   int counter = 0;
   if (Ethernet.begin(mac) == 0) {
      while (1) {
         delay(500);
         Serial.print(".");

         counter++;
      }

   }
}
/*-------------------------------------------------------------------------
                           main loop
-------------------------------------------------------------------------*/
void loop() {
  // put your main code here, to run repeatedly:
  updateData();
  delay(10000); //10 sec
}

/*-------------------------------------------------------------------------
                     update time from NTP server
-------------------------------------------------------------------------*/
void updateData(){
  Serial.println("Updating time...");
  timeClient.update_time();
  Serial.println(timeClient.getFormattedDate("/"));
  Serial.println(timeClient.getFormattedTime());
}

