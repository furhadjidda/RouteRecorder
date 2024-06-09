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

#ifndef MOCK_ARDUINO_H
#define MOCK_ARDUINO_H

#include <iostream>
#include <string>
#include <cstdint>

typedef uint8_t byte;

class String {
public:
    String(const char* cstr = "") : str_(cstr) {}
    String(const std::string& str) : str_(str) {}
    String(const String& other) : str_(other.str_) {}
    String(byte value) : str_(std::to_string(value)) {}

    const char* c_str() const { return str_.c_str(); }

    String& operator=(const String& other) {
        if (this != &other) {
            str_ = other.str_;
        }
        return *this;
    }

    String& operator+=(const String& other) {
        str_ += other.str_;
        return *this;
    }

    friend String operator+(const String& lhs, const String& rhs) {
        return String(lhs.str_ + rhs.str_);
    }

    friend String operator+(const char* lhs, const String& rhs) {
        return String(std::string(lhs) + rhs.str_);
    }

    friend String operator+(const String& lhs, const char* rhs) {
        return String(lhs.str_ + std::string(rhs));
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.str_;
        return os;
    }

private:
    std::string str_;
};

class SerialClass {
public:
    void begin(int baud) { std::cout << "Serial started at " << baud << " baud\n"; }
    void println(const char* msg) { std::cout << msg << "\n"; }
    void println(int msg) { std::cout << msg << "\n"; }
};

extern SerialClass Serial;

#endif // MOCK_ARDUINO_H
