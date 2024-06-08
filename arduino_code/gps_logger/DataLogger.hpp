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

#include <SPI.h>
#include <SD.h>
#include <Adafruit_GPS.h>

class DataLogger{
    public:
        void InitAndPrepare();
        // lat and lon are expected to be in the decimal degrees format
        void Write( String timeStamp, float lat, float lon );

    private:
        const int chipSelect{SDCARD_SS_PIN};
        const String mFileName{"gpsdata.csv"};
};