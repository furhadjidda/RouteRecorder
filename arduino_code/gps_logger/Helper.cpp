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

#include "Helper.hpp"
#include <cmath>
// Reference : https://stackoverflow.com/questions/36254363/how-to-convert-latitude-and-longitude-of-nmea-format-data-to-decimal
float Helper::ConvertToDecimalDegrees(float rawDegrees, char direction)
{

    int degrees = int(rawDegrees / 100);
    float minutes = rawDegrees - (degrees * 100);
    float decimalDegrees = degrees + minutes / 60.0;

    // Apply the direction (N/S/E/W)
    if (direction == 'S' || direction == 'W') {
      decimalDegrees *= -1;
    }
    // This is done so that the number is truncated to 6 decimal places 
    double scale = pow(10.0,6);
    return floor(decimalDegrees*scale)/scale;
}


String  Helper::FormatDateAndTime( uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
{
    String timestamp = "20" + String(year) + "-" +
                String(month) + "-" +
                String(day) + "T" +
                String(hour) + ":" +
                String(min) + ":" +
                String(sec) + "Z";
    return timestamp;
}