/*
* Route Mapper Code Test code
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

#include <gtest/gtest.h>
#include "Helper.hpp"
#include "mocks/Arduino.h"
#include "mocks/Wire.h"

TEST(Helper, Test1) {
    Helper helper;    
    EXPECT_EQ(helper.ConvertToDecimalDegrees(3850.2292,'N'), float(38.8371544));
    EXPECT_EQ(helper.ConvertToDecimalDegrees(9447.3447,'W'), float(-94.789078));
}