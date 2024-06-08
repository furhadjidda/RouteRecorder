/*
* Route Mapper Code
* Copyright (C) 2024  Furhad Jidda
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <Adafruit_GPS.h>
#include "DataLogger.hpp"
#include "Helper.hpp"

#define GPS_DEBUG true

// Data Logger Instance
DataLogger dataLogger;
Helper helper;

// GPS instance Connect to the GPS on the hardware I2C port
Adafruit_GPS GPS(&Wire);

// To keep track of time elasped
uint32_t timer = millis();


void setup()
{
    while (!Serial);
    Serial.begin(115200);


    // Ask for firmware version
    Serial.println("\n\n== Setting up Route Mapper ===\n\n");
    dataLogger.InitAndPrepare();

    // 9600 NMEA is the default baud rate for Adafruit MTK GPS's- some use 4800
    GPS.begin(0x10);  // The I2C address to use is 0x10
    // uncomment this line to turn on RMC (recommended minimum) and GGA (fix data) including altitude
    GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
    
    // Set the update rate
    GPS.sendCommand(PMTK_SET_NMEA_UPDATE_2HZ);

    // Request updates on antenna status, comment out to keep quiet
    GPS.sendCommand(PGCMD_ANTENNA);

    delay(1000);
}

void loop()
{
    // read data from the GPS in the 'main loop'
    // This is the method that is required to be called before anything can be read over I2C , 
    // infact this method actually does that read.
    // Without calling this call none of the other API's will provide any data as there will 
    // be no data to provide.
    GPS.read();

    // if a sentence is received, we can check the checksum, parse it...
    if (GPS.newNMEAreceived()) {
        // Only if GPS_DEBUG is true will the NMEA sentences will be logged to serial console else it is just noise
        // that we do not need to see all the time.
        if( GPS_DEBUG ){
          Serial.println(GPS.lastNMEA()); // this also sets the newNMEAreceived() flag to false
        }
      
        if (!GPS.parse(GPS.lastNMEA())) // this also sets the newNMEAreceived() flag to false
          return; // we can fail to parse a sentence in which case we should just wait for another
    }

    // approximately every 3 seconds or so, print out the current stats
    if (millis() - timer > 3000) {
        timer = millis(); // reset the timer
        Serial.println(GPS.milliseconds);
        Serial.print("Fix: "); Serial.print((int)GPS.fix);
        Serial.print(" quality: "); Serial.println((int)GPS.fixquality);
        if (GPS.fix) {
          Serial.print("Altitude: "); Serial.println(GPS.altitude);
          Serial.print("Satellites: "); Serial.println((int)GPS.satellites);
        }

        String timestamp = helper.FormatDateAndTime(GPS.year, GPS.month, GPS.day, GPS.hour, GPS.minute, GPS.seconds );
        Serial.print("timestamp: "); Serial.println(timestamp);
        dataLogger.Write( timestamp, helper.ConvertToDecimalDegrees(GPS.latitude, GPS.lat), helper.ConvertToDecimalDegrees(GPS.longitude, GPS.lon) );
    }
}