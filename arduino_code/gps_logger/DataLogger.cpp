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

#include "DataLogger.hpp"


void DataLogger::InitAndPrepare()
{
        // see if the card is present and can be initialized:
    if (!SD.begin(chipSelect)) {
      Serial.println("Card failed, or not present");
      // don't do anything more:
      while (1);
    }

    SD.remove(mFileName);
    File dataFile = SD.open(mFileName, FILE_WRITE);
    dataFile.print("timestamp,latitude,longitude,altitude\n");
    dataFile.close();
}

void DataLogger::Write(String timeStamp, float lat, float lon)
{
    // Open the file for appending
    File dataFile = SD.open(mFileName, FILE_WRITE);
    if (dataFile) {
      // Write data in CSV format      
      dataFile.print(timeStamp);
      dataFile.print(",");
      dataFile.print(lat, 6);
      dataFile.print(",");
      dataFile.print(lon, 6);
      dataFile.print("\n");
      dataFile.close();
      Serial.println("Data written to gps_data.csv");
    } else {
      Serial.println("error opening gps_data.csv");
    }
}